//Cracked by Roath
// Room: /d/beijing/gulou.c

inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
���ǹ�¥ÿ��������ʱ�ֱ�Ὺʼ��ģ���������������
ƽ�����������¥��������֪��ʱ���ˡ���¥������ǳ���
�����Ĺ�¥��֣����������ֵĶ�ֱ�Ŵ�֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"dianmen",
        "west" : __DIR__"guloudajie_w",
        "north" : __DIR__"zhonglou",
        "east" : __DIR__"guloudajie_e",
        "up" : __DIR__"gulou2",
        ]));
        
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);

        setup();
        replace_program(ROOM);
}
