// room /d/wulin/fachu.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������Ƿ��񴦣�����ʹ��ͨ�����⴦�������ƻ�����ͬ�˵����ְ��࣬��
�ϵ��������˸����̾ߣ�ǽ�ϻ���δ�ɵ�Ѫ����������������һ��Ѫ�ȵ�ζ����
LONG
        );

        set("exits", ([
         "west" : __DIR__"zhengqiting",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
