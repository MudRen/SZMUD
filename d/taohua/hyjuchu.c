// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "��ҩʦ�Ӵ�");
	set("long", @LONG
�����һ�������ҩʦ�����ң�һ����齿����ݶ����ǣ���ǰһ��������һ����
�٣�һ�����ס�������ɫ���ɣ���β����ȫ�ս������������һ��ֽ�����Կ���һ
Щ�ּ���������ȥ���������Կ���һ�����㡣
LONG
	);
	set("objects", ([
		__DIR__"obj/paper2" : 1,
		"/kungfu/class/taohua/huang" : 1,
	]));
	 set("exits", ([
                "east" : __DIR__"changlang2",
        ]));
	setup();
	replace_program(ROOM);
}
