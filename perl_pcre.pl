

my $url = "http://www.google.com.hk/search?hl=zh-CN&newwindow=1&safe=strict&q=ipad&aq=f&aqi=g-s6g2g-s1g1&aql=&oq=";

my $i = 0;
do {
    if ($url =~ /q=([^&]+)/) {
        #print "$1\n";
    }
    $i = $i + 1;
} until ($i > 1000000);

