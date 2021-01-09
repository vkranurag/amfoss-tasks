package main
import (
	"context"
	"log"
	"fmt"
	"github.com/vartanbeno/go-reddit/reddit"
	"time"
)
var ctx = context.Background()
func main() {
	if err := run(); err != nil {
		log.Fatal(err)
	}
}
func run() (err error) {
	withCredentials := reddit.WithCredentials("ID", "sec", "user", "pass")
    	client, _ := reddit.NewClient(withCredentials)
	sr,_,err:=client.Subreddit.Get(ctx,"memes")
	if err!=nil{
		return err
	}
	posts,_,err:=client.Subreddit.HotPosts(ctx,sr.Name,&reddit.ListOptions{Limit:100})
	for _,post:=range posts{
		if err == nil {
			date := time.Now()
			format := "2006-01-02 15:04:05"
			posted,_ := time.Parse(format,post.Created.Format(format))
    			diff := date.Sub(posted)
    			if (int(diff.Hours()/24)>=7 && int(diff.Hours()/24)<=14){
				_, err := client.Post.Upvote(ctx,"t3_"+post.ID)
				if err !=nil{
					fmt.Println("Error for upvoting post with ID:"+post.ID);
				}
			}
		}
	}
	return
}
