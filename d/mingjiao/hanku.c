// Code of ShenZhou
// room: /mingjiao/hanku.c

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
�����Ѵ����ر�´�ľ�ͷ��ɽ�����ãã��Į����˵�����Ѿ�������
��˴�ʱ�����޸��ˣ���ʹ��һ��һҹ�����Ϊ֮��ɫ���ʶ���ɽ������
���ޡ�������֮����ɽ��һ���ʯ�Ͼ�����������ȥ����ۣ��ʴ˳�Ϊ��
���ʯ(leihenshi)����
LONG );

        set("exits", ([
                "north" : __DIR__"?????",
                "southdown" : __DIR__"yinshandao",
        ]));

        set("item_desc", ([
                "leihenshi"    : "����һ�鰵��ɫ�ľ�ʯ��Լ��
��ͨԲ����С����ϸ��ʱ����������߰ߵ�㣬ȷʵ�������һ�㡣\n",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}