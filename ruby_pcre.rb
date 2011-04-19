

re = Regexp.new(/q=([^&]+)/)
url = String.new("http://www.google.com.hk/search?hl=zh-CN&newwindow=1&safe=strict&q=ipad&aq=f&aqi=g-s6g2g-s1g1&aql=&oq=")

i = 0
until i > 1000000 do
  url.match(re)
  i = i + 1
end

