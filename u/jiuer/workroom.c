 // WizRoom: workroom.c
 // Jiuer/8/01/2000
// new here

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"ʫ԰"NOR);
	set("long", @LONG

����������������������������������������������������������	
������������������������������������������������������������
��������������ĬĬ�����ĵط�  ����������Ʒ���ɹ�����԰  �� 
����������������������������������������������������������
�����������ǵĸп����䵽���  �������ǵĻ�Ц�ص����ı�  ��
����������������������������������������������������������
����������������������������������������������������������

LONG);
        set("valid_startroom",1);	
	    set("quickquit", 1);       
	    set("exits", ([ 
			"hs"  : "/d/huashan/pianting",
			"qzhou"  : "/d/quanzhou/zhongxin",
			"yz"  : "/d/city/kedian",
			"qz" : "/d/zhongnan/taijie2",
			"ts"  : "/d/taishan/fengchan",
			"sl"  : "/d/shenlong/dating",
			"wud" : "/d/wudang/sanqingdian",
			"gb"  : "/d/gaibang/undertre",
			"xx"  : "/d/xingxiu/xxh2",
			"em"  : "/d/emei/hz_guangchang",
			"bt"  : "/d/baituo/btyard",
			"xs"  : "/d/xueshan/guangchang",
			"kl"  : "/d/kunlun/guangchang",
			"bj"  : "/d/beijing/changanjie",
			"xi"  : "/d/xixia/dawu",
			"gy"  : "/d/taihu/qianyuan",
			"dl"  : "/d/dali/wangfu1",
			"hz"  : "/d/hangzhou/kedian",
			"gm"  : "/d/gumu/dating",
			"wr"  : "/d/wizard/wizard_room",
]));
      setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && dir != "yz")
		return notify_fail("��û������ʲô? \n");
	return ::valid_leave(me, dir);
}

