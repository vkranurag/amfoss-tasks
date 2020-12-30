import 'package:flutter/material.dart';
import 'package:dots_indicator/dots_indicator.dart';

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final PageController _pageController = PageController(initialPage: 0);
  double _currentPage = 0;
  double rt = -175;
  int i = 2;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Container(
          child: Padding(
            padding: EdgeInsets.symmetric(vertical: 0.0),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.stretch,
              children: <Widget>[
                SizedBox(height: 70.0),
                DotsIndicator(
                  dotsCount: 2,
                  position: _currentPage,
                  decorator: DotsDecorator(
                    size: const Size.square(9.0),
                    activeSize: const Size(108.0, 9.0),
                    activeColor: Color(0xFF6C29D0),
                    activeShape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(5.0)),
                  ),
                ),
                Container(
                  height: 600.0,
                  child: PageView(
                    physics: ClampingScrollPhysics(),
                    controller: _pageController,
                    onPageChanged: (int page) {
                      setState(() {
                        _currentPage = page.toDouble();
                        if (i % 4 == 1)
                          rt = -175;
                        else
                          rt = -150;
                        i++;
                      });
                    },
                    children: <Widget>[
                      Padding(
                        padding: EdgeInsets.all(0.0),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: <Widget>[
                            SizedBox(height: 35.0),
                            Stack(
                              children: <Widget>[
                                Positioned(
                                  child: Image.asset(
                                    'assets/images/img1.png',
                                    width: 200.0,
                                    height: 300.0,
                                    alignment: Alignment.topLeft,
                                  ),
                                ),
                                Positioned(
                                  bottom: -90,
                                  right: rt,
                                  child: Image.asset(
                                    'assets/images/img2.png',
                                    width: 200.0,
                                    height: 200.0,
                                  ),
                                ),
                              ],
                              overflow: Overflow.visible,
                            ),
                            SizedBox(height: 35.0),
                            Text('   Hello!',
                                style: TextStyle(
                                  color: Color(0xFF6C29D0),
                                  fontSize: 20.0,
                                  fontWeight: FontWeight.bold,
                                )),
                            SizedBox(height: 5.0),
                            Text(
                                '  Your own\n  private Cloud is\n  one step away.',
                                style: TextStyle(
                                  color: Colors.black,
                                  fontSize: 30.0,
                                  fontWeight: FontWeight.bold,
                                )),
                            SizedBox(height: 20.0),
                            Text('     Swipe left to get started.',
                                style: TextStyle(
                                  fontSize: 15.0,
                                  fontWeight: FontWeight.bold,
                                  color: Color(0xFF6C29D0),
                                )),
                          ],
                        ),
                      ),
                      Padding(
                        padding: EdgeInsets.all(20.0),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: <Widget>[
                            SizedBox(height: 35.0),
                            Center(
                              child: Image(
                                image: AssetImage(
                                  'assets/images/img3.png',
                                ),
                                height: 250.0,
                                width: 400.0,
                              ),
                            ),
                            SizedBox(height: 85.0),
                            Text('Your Premium Cloud',
                                style: TextStyle(
                                  color: Color(0xFF6C29D0),
                                  fontSize: 20.0,
                                  fontWeight: FontWeight.bold,
                                )),
                            SizedBox(height: 15.0),
                            Text(
                                'Launch your next\ncampaigns within minutes\nwith Cloud Campaign\nMonitor.',
                                style: TextStyle(
                                  color: Colors.black,
                                  fontSize: 25.0,
                                  fontWeight: FontWeight.bold,
                                )),
                          ],
                        ),
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ),
        ),
        bottomSheet: Container(
          height: 50.0,
          width: double.infinity,
          margin: EdgeInsets.all(25),
          padding: EdgeInsets.all(10),
          decoration: BoxDecoration(
              color: Color(0xFF6C29D0),
              borderRadius: BorderRadius.circular(10.0),
              border: Border.all(color: Color(0xFF6C29D0), width: 3.0)),
          child: Center(
            child: Padding(
              padding: EdgeInsets.only(bottom: 00.0),
              child: Text(
                'Create an account',
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 20.0,
                  fontWeight: FontWeight.bold,
                ),
              ),
            ),
          ),
        ));
  }
}
