// room /d/wulin/shangchu.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "���ƴ�");
        set("long", @LONG
����������ƴ�������ʹ�߾��������ｱ��Ϊ����ͬ������ͻ�����׵���ʿ��
Ϊ���ǰ䷢��Ʒ����������������ĸ������ĺ��ӡ�
LONG
        );

        set("exits", ([
         "east" : __DIR__"xiayitang",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
