// Code of ShenZhou
// room: /mingjiao/yushuquan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
�������������赲�غ�Х�����������ϱ����Ǹ�ɽ����Ȼ�γɸ���
��ڣ������˼���վ�����ȡ��ȵ������ɿ�ˮ��������������һЩ�ͺ���
����������Ĵ�ɽ����ȥ������һ����Ȼ���䡣
LONG );

        set("exits", ([
                "northup" : __DIR__"suibei",
                "east" : __DIR__"xinkaiquan",
                "southup" : __DIR__"yinan",
                "west" : __DIR__"????",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 1);

        setup();
        replace_program(ROOM);
}