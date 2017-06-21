#include <iostream>
#include <cstdio>
int main() {
  int n,xstart,ystart,xend,yend,
    xleft,ytop,xright,ybottom;
  float m,b,x,y;
  std::string str="";
  scanf("%i",&n);
  while(n--){
  	scanf("%i%i%i%i%i%i%i%i",
  	  &xstart,&ystart,&xend,&yend,
      &xleft,&ytop,&xright,&ybottom);
    if(xleft>xright)
      xleft^=xright^=xleft^=xright;
    if(ytop<ybottom)
      ytop^=ybottom^=ytop^=ybottom;
    if((xstart>=xleft && xstart<=xright &&
          ystart>=ybottom && ystart<=ytop) ||
          (xend>=xleft && xend<=xright &&
           yend>=ybottom && yend<=ytop)){
      str+="T\n";
    } else if(xstart==xend){
      if(ystart>yend)
        ystart^=yend^=ystart^=yend;
      if(xstart>=xleft && xstart<=xright &&
          ((yend>=ytop && ystart<=ytop) ||
          (yend>=ybottom && ystart<=ybottom)))
        str+="T\n";
      else
        str+="F\n";
    } else {
    	m=(float)(yend-ystart)/(xend-xstart);
    	b=ystart-m*xstart;
    	if(xstart>xend)
    	  xstart^=xend^=xstart^=xend;
    	if(ystart>yend)
    	  ystart^=yend^=ystart^=yend;
    	y=m*xleft+b;
    	if(y<=ytop && y>=ybottom &&
    	    xleft>=xstart && xleft<=xend)
    	  str+="T\n";
    	else {
          y=m*xright+b;
    	  if(y<=ytop && y>=ybottom &&
    	      xright>=xstart && xright<=xend)
    	    str+="T\n";
    	  else if(m==0){
    	  	str+="F\n";
    	  } else {
    	  	x=(ytop-b)/m;
    	  	if(x>=xleft && x<=xright &&
    	  	    ytop>=ystart && ytop<=yend)
    	  	  str+="T\n";
    	  	else {
    	  	  x=(ybottom-b)/m;
    	  	  if(x>=xleft && x<=xright &&
    	  	      ybottom>=ystart && ybottom<=yend)
    	  	    str+="T\n";
    	  	  else
    	  	    str+="F\n";
    	  	}
    	  }
    	}
    }
  }
  std::ios_base::sync_with_stdio(false);
  std::cout<<str;
  return 0;
}
