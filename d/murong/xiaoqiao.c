// Code of ShenZhou
//ROOM: xiaoqiao.c

inherit ROOM;

void create()
{        set("short", "Сʯ��");
        set("long", @LONG
    һ��С��ʯ�ţ������ϵ�����������ǻ��Ļ��ƣ��ŵ�
���϶�������һ��Сľ�ݡ�վ�����ϣ�������Ŀ��������þò�
Ը��ȥ
LONG
	);
             
        set("exits", ([
                "southwest" : __DIR__"road1",
                "north" : __DIR__"lianwu",
        ]));    
        setup();
        replace_program(ROOM);
}