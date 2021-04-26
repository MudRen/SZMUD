// final��СС����

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
	set("short",REF ""HIC"�����ɾ�" NOR);
	set("long",	"
	"HIC"��"YEL"��"HIW"Ǭ��"NOR","HIM"Ψ��"HIG"�����ɾ���"NOR"

    "HIW"Ǭ��"HIG"�ɾ�"U"��̳"NOR"��"CYN"��ȥ��ȥ��"YEL"��֮����

"HIC"------------------------------------------------------        
""			"HIW"Ǭ��
	"HIM"�����һ�(th)  "NOR"����ؤ��(gb)  "HIG"���ϴ���(dl)"NOR"
		--------------------
			 "HIC"Ǭ
  "YEL"   �䵱(wd)  ȫ��(qz)  ����(sl)  ��ɽ(hs)  ����(em)
	       "NOR" --------------------
			 "WHT"��
	 "YEL"����(xx)  ѩɽ(xs)  Ѫ��(xd)  ����(bt)
"HIC"------------------------------------------------------
			"HIW"OTHER
------------------------------------------------------
����(yz)  ����(hz)  ����(xi)  Ȫ��(ql)  ��ɽ(fs)
����(jx)  ̫��(gy)  ����(yl)  ����(lz)  ������(sbg)
����(bj)  ����(ny)  ѩ��(xd)  ����(cb)  ��ľ��(hm)
����(dl)  ��ɽ(hx)  ����(kl)  Ľ��(mr)  ����(so)

"NOR""	);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"yumiko" : 1,
	]));
					      
	set("valid_startroom",1);
					      
	set("exits", ([
              //  "kl" : "/d/kunlun/wall5",
			  "zn" : "/d/zhongnan/dadian",
			    "f"	 :	"/d/final/pingyuan1",
				"kl" :  "//d/kunlun/damen",
                "sl" : "/d/shaolin/smdian",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wd" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gy" : "/d/taihu/qianyuan",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
				"th" : "/d/taohua/shuilong",	
				"yz" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "wr": "/d/wizard/meeting_room",                                                             
	]));

	setup();
	//replace_program(ROOM);
}

void init()
{
	object me = this_player();

	if( wizardp(me) && getuid(me)!="final ")
		message("vision", me->name()+"���˹�����\n", environment(me), ({me}));

	add_action("do_leave", "leave");
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("�����ȵ�������ǰ������˵�������ǳ���Ǹ�������ܵ��Ƕ�ȥ����\n");

	return ::valid_leave(me, dir);
}

int do_leave()
{
	object me = this_player();
	if(me)
		me->move("/d/city/wumiao");
	return 0;
}

