//Cracked by shenzhou
//maco
//modified by jiuer May 2002

#include "room.h"

inherit ROOM;
string long_desc();

void create()
{
	int i;
	set("short", "����");
	set("long", (: long_desc :));

	i = random (4);
	switch (i) {
	case 0:
		set("objects", ([
			"/d/jiaxing/obj/yaoqin" : 1,
			"/d/taohua/obj/music_book" : 1,
			]));
	break;
	case 1:
		set("objects", ([
			"/d/taohua/obj/zhuxiao" : 1,
			"/d/taohua/obj/music_book" : 1,
			]));
	break;
	case 2:
		set("objects", ([
			"/d/jiaxing/obj/yaoqin" : 1,
			"/d/taohua/obj/zhuxiao" : 1,
			"/d/taohua/obj/music_book" : 1,
			]));
    break;
	case 2:
		set("objects", ([
			"/d/taohua/obj/music_book" : 2,
			]));
	}

	set("exits", ([
		"west" : __DIR__"maoshe",
		]));

	set("sleep_room", 1);
    set("no_fight", 1);
    set("cost", 1);
    setup();
}

string long_desc()
{
        string desc;
        desc  = "����é����һ�䶷�ң��崲ľ�ʣ���Լ�ª���ı���Ȼ��ȴ��һӦ��Ⱦ����
�ľ��ף�";

        if (present("zhu xiao", this_object()) && present("yao qin", this_object())  )
		{
desc += "������̨�ϲ�����һ�����٣�һ��������мž���������֮��������
�����Ƶ�����һ���硣\n" ;
	}
	else if (present("zhu xiao", this_object()))
	{
desc += "������̨�Ϸ�����һ��������мž���������֮�������������Ƶ���
��һ���硣\n" ;
	}
        else if (present("yao qin", this_object()))
		{
desc += "������̨�Ϸ�����һ�����١����мž���������֮�������������Ƶ���
��һ���硣\n";
	}
	else desc += "���߰�����һ�β������мž���������֮�������������Ƶ�����һ��
�硣\n";

        return desc;
}

