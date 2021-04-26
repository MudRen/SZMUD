// Code of ShenZhou
// room: /mingjiao/badake.c

inherit ROOM;

void create()
{
        set("short", "�ʹ��ɽ");
        set("long", @LONG
��������վ��쳣�����Ǽ���ɽ�崦��Σ���ͱڡ��������������·��
��������Զ����Ծǰ����ɽ���ϻ�����ѩ�����ǻ������һ��ʧ�㣬
�ػ�ˤ�÷�����ǡ�����˵�����������ǡ��ʹ�ˡ���ԭ����ǡ���
����Խ����
LONG );

        set("exits", ([
                "southdown" : __DIR__"xingzi",
                "eastdown" : __DIR__"bailongdui",
                "northwest" : __DIR__"shanlu2",
        ]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 3);

        setup();
        replace_program(ROOM);
}