//room /d/wulin/zoulang.c 
// updated by Lara 2001/10/14
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ���������ɴ��������ɵ����ȣ���Χ�������񣬷�βɭɭ��
����ϸϸ�����˾���Ϊ֮һ�����ȵ����԰����˾����辰������һ����
Ȥ���������߾����������ˡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"dianmen",
                "north" : __DIR__"xiayitang",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
       replace_program(ROOM);
}
