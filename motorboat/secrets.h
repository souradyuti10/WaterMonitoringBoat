#include <pgmspace.h>
 
#define SECRET
 
const char WIFI_SSID[] ="SOURA";               //TAMIM2.4G
const char WIFI_PASSWORD[] = "password";           //0544287380
 
#define THINGNAME "ESP8266"
 
int8_t TIME_ZONE = -5; //NYC(USA): -5 UTC
 
const char MQTT_HOST[] = "a1nsvxavloql1t-ats.iot.us-west-2.amazonaws.com";
 
 
static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
 
// Copy contents from XXXXXXXX-certificate.pem.crt here ▼
static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUENwMHE7bREUCpCnfb+N62FYFicgwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDQwMTE1NTkx
N1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALlno8g1/WvUECjcBGeK
PcoY8HLbQ+egda6Y3/4DvHIV5MuJ2mImjK7bZoOZtcfwRsmRX9oROKQ2QFQiFOgQ
b3T3wb8oa0uPQqs0DvkxsU3788TGBSlX18vX7Yz1qkUpJYe+7mOd3E8eV4ZRqofj
zWMZa8bVqmbvNBhedxYB6RfI+RnUCNVefyLkeVhJ8SJKR3eikeariDOXjD9lOzfM
SJ4Ds1PJEzM17pw9M39jIluXzAFUUB8iDRgjKOoSN84Yc6KAXgTQoOtpO8H9tTLY
YzqrdFrwICwe1fJ/u3avILREyNne3On8O8OMwTQIhYmfQlBmjJidJ2zcMAL3zXjr
mN8CAwEAAaNgMF4wHwYDVR0jBBgwFoAUeuTIBPAj70rJmlUUMngds8BKoNwwHQYD
VR0OBBYEFNf5Di+0alZ1fU79xgLyMyjkd1MFMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBqyEmQ/VHjN/mj+mwmVa9YJRrf
p62FUb3csIjeTb2LDkIym2nIs5jTpHqqwHK5mMJc9buhC+dttJtFKG0rg5kas7gM
oQmQCsuFy/S775p62IuP15pWIJBlqDW/cPCm0hYRfMgIVJS7Ua6AaU30JUSBVHK8
HUcsezwKTGIf+BLaWoxJMlT+tqx0RQHO8vKsD69zzKk9lMvMp6mtb0TQwoYFECRk
HWgDnNg4q1kg0uq40iyWEa40w+E2jQtlAihNDlijUVUPsnsmPikC0wjO4YT5P4Jr
yjMmUTNwO+9kYOIyjQbwE51r3CxP04Iaa09SdTn1mTGFUzYm7yXFvNZ6I12p
-----END CERTIFICATE-----
)KEY";
 
 
// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAuWejyDX9a9QQKNwEZ4o9yhjwcttD56B1rpjf/gO8chXky4na
YiaMrttmg5m1x/BGyZFf2hE4pDZAVCIU6BBvdPfBvyhrS49CqzQO+TGxTfvzxMYF
KVfXy9ftjPWqRSklh77uY53cTx5XhlGqh+PNYxlrxtWqZu80GF53FgHpF8j5GdQI
1V5/IuR5WEnxIkpHd6KR5quIM5eMP2U7N8xIngOzU8kTMzXunD0zf2MiW5fMAVRQ
HyINGCMo6hI3zhhzooBeBNCg62k7wf21MthjOqt0WvAgLB7V8n+7dq8gtETI2d7c
6fw7w4zBNAiFiZ9CUGaMmJ0nbNwwAvfNeOuY3wIDAQABAoIBAQC0X/cAXj5JfEuo
ZLzIOr74ciDjrRw4KWy0SziH+PyKBXDM8DWNDbIKn5rxZ0Zp2QIVMiCNl/mCEOGu
uGWci/jTVAKjReB051BWHVR/7W9wzjEPfBMjcLmaMF2EqLBZjrlbgk6MjdT7CCrg
m20LvX1g7ydijxa0A/2rw6OZvowWPSDj7YjQOdAeAPi+Tr8qYIY0mFQ6Fp9hHEcJ
mmryll6+YQP/U1rMomEuACBOLgmb9xUufo6c2Ptb6A/muGxQz9Q3HBp6ppOnL4Ab
+0h3grfdSMy/ZBmqJFxhPoH5vQBwlwP7kuXypnJHFZUO0pJjTg31z113jmByhL+o
8NKuCeupAoGBANxeBNvcRgK8PQuK+7MNaRveeX7SJrkYUzuYnTbOVIsfg9UmO0rV
tEno5EgvXSDBVf7YIlbTtOlX0YJqdCbckzEAmWp57Wlojv8n2w4xZbUl8fogxKfw
1rJWXvHDlQh+S4sCa3gQBV/oTWE3ViuXZUAg5I0FGPefm7fVxn4uxiT9AoGBANdi
XuwIkDo7iQkU4p2GQ4a+uk9lyhePdz4CgDmFG0ZSh+eWiB/3mROLYS5bF34yGyfB
eUMG01wYip4fs/XidZGvtXh89oEW0zib78NQJcfrEapX+YJhfVRNhUDZ766hgjsr
T58EKV+R/wxTkb1ddOSptvXupvQhJZ+mgew8uKoLAoGAU+W7pdUEFpCCET31u+KU
LNcTnHP36CpZrevZlv8Q8vKpp2Hp2wDnpefz2YOmygyxZ9fzoujxDJGxoxxSYmVB
6LsYrZAEEkiLgJs06/9kgIYUzSzikinAI598gED9IYGr0x21ur0mvq/bnfKKbQgz
tSmQuhvBuKzchS3vZyT5rSUCgYBRzMB0MERmeVnwIwh1/xoCQMmNggEgtZH58QU1
00GqkYmgAOGuEmEGtTaxXlMr0GfTz3z4Yc0/+uoaZ7v3NIymSe9H1V3hZQPPShnj
Obs/lB1fbo4KYHAy5kYnfR20Ww6U3jwdDn2QGGifC9Yb7zSH65TbDkpGCZi6a4iI
af9QRQKBgF6vBJcVRSDcl0jBG2gPsiXksFhduvw4S5v6P5+D+xoCGwYpGCq6RAVN
xRnwrQtsdUvQutph6pOFyvM2w9/4qQ+ISt1BnTnsTnLIJIGCeUXWcYK1tNwlWMB8
2ViKN7DVYlSECTMZ+lAdvEwwLtDcokMoNK7jpWTgBYxHrHuBryWG
-----END RSA PRIVATE KEY-----
 
)KEY";