// room /d/wulin/xiaolu7.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
ɽ·���쵽����ֱ�ÿ�������Ȼ�γ�һ��ƽ̨������ɽ����ȥ��ֻ
��Ⱥɽ���ƣ����������де�ɭ�֣��������������۵ף����ɵú���������
�����ƺ��к��Ӵ��һ��������

LONG
        );

        set("exits", ([
         "west" : __DIR__"xiaolu6",
         "north" : __DIR__"xiaolu8",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
