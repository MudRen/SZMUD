// Code of ShenZhou
// room: /mingjiao/yinshandao.c

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
�����Ǻ�����Ϊ�޽���һ��ɽ������˵�˵��޳ɺ�ÿ��������ϡ֮
ҹ����������������ɫ���󣬹ʶ������������վã��˵������˲��٣���
����Ȼƽ̹���С�
LONG );

        set("exits", ([
                "south" : __DIR__"tushantai",
                "northup" : __DIR__"hanku",
                "westup" : __DIR__"jicongling",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 1);

        setup();
        replace_program(ROOM);
}