// Code of ShenZhou
// room: /mingjiao/shanlu.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ֻ���˴���·��᫣������վ���һ�����ذ�������բʯ�š����漴��
��������ɽ�ڡ����Ҷ���ɽ��Ĳ������֪ͨ��η���
LONG );

        set("exits", ([
                "northup"   : __DIR__"shankou",
                "southdown" : __DIR__"shanlu1",
                "westup"    : __DIR__"shanlu3",
                "eastup"    : __DIR__"shanlu4",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
