// Code of ShenZhou
// Room: /d/murong/lianwu
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "˽��");
	set("long", @LONG
    ���˽����ΪĽ���ϵ��ӵļҾ쿪��ģ�Ƹ����һ��
��ؿ�����������ڿΡ�
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "west" : __DIR__"lianwu1",
                      ]));

	set("no_clean_up", 0);
       

        set("objects", ([
		"/d/city/npc/xiucai" : 1,
		]));

	setup();
	replace_program(ROOM);
}

