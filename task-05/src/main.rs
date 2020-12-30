use reqwest;
use scraper::{Selector, Html};
use csv::Writer;

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let resp = reqwest::get("https://www.worldometers.info/coronavirus/#countries").await?;
    assert!(resp.status().is_success());
    let body = resp.text().await?;
    let fragment = Html::parse_document(&body);
    let countries = Selector::parse("#main_table_countries_today tbody:nth-child(2) tr:not([style*=\"display: none\"])").unwrap();
    let mut cnt = 0;
    let mut csvdata = Writer::from_path("coronadata.csv")?;
    //csvdata.write_record(&["a", "b", "c"])?;
    for country in fragment.select(&countries) {
        let mut countrydata = country.text().collect::<Vec<_>>();
        if cnt==0 {cnt+=1;continue;}
        countrydata.retain(|ele| *ele != "\n");
        countrydata.retain(|ele| *ele != "\n ");
        countrydata.retain(|ele| !ele.starts_with("+"));
        println!("{:?} {:?} {:?} {:?}",countrydata[1],countrydata[2],countrydata[3],countrydata[4]);
        let x=countrydata[1];
        let y=countrydata[2];
        let z=countrydata[3];
        let a=countrydata[4];
        let pos = countrydata[0];
        csvdata.write_record(&[pos,x,y,z,a])?;
        //println!("{:?}",countrydata);
        if cnt >= 10 { break; }
        else {cnt += 1;}
    }
    csvdata.flush()?;
    Ok(())
}
