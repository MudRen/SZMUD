// Code of ShenZhou
// room: xiangfang2.c

inherit ROOM;

void create()
{
        set("short", "Ů�᷿");
        set("long", @LONG
��������ӥ��Ů����˯���ĵط���һ���ž��ŵ�һ�����Ƶ�������
ǽ���Ϲ���һ��������Ůͼ������һ�ż��Ϲ���һ��������
LONG );

        set("exits", ([
                "north" : __DIR__"yuanzi",
        ]));

	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);
        
	setup();
        replace_program(ROOM);
}
