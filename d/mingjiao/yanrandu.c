// Code of ShenZhou
// room: /mingjiao/yanrandu.c

inherit ROOM;

void create()
{
        set("short", "��Ȼ��");
        set("long", @LONG
������治������Ҳ��Ϊƽ�ȣ�������һ���ɿڣ����ǿ���ȥ�Ѿ�
�ƾɲ�����������һЩ̤��ľ׮֮�࣬����ȥ֨֨�¸������졣�ڰ���һ
վ������Ҳ����һ����Ӱ��
LONG );

        set("exits", ([
                "north" : __DIR__"tongtianhe",
                "east" : __DIR__"luobuyi",
                "south" : __DIR__"luyuhe",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 1);

        setup();
        replace_program(ROOM);
}