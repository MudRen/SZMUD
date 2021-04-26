// Code of ShenZhou
// harbor.h  ���иۿ�����
// by ALN@XKX

// locx indicates positions of easts-wests, + means east, - means west
// locy indicates positions of south-norths, + means north, - means south

// all ��½�ۿ�
mapping harbors = ([
        "/d/beijing/tanggu"    :    0,
        "/d/jiaxing/zhoushan"   : -200,
        "/d/quanzhou/yongning" : -280,
        "/d/quanzhou/anhai"    : -300,
]);

// all �����ۿ�
mapping islands = ([
        "/d/shenlong/beach"    : ({ 30,   20}), 
        "/d/island/icefire1"   : ({100,  600}),
        "/d/taohua/haitan"     : ({ 20, -210}),
]);

// �ĵ�
// �����ͣ�ڻĵ�����ҿ�����һ�����ش�
// ��Ϊ�ڻĵ�������޷�����
string *wildharbors = ({
        "/d/island/icefire1",
});
