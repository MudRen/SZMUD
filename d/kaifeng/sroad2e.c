//Room: /d/kaifeng/sroad2e.c
// by bravo
inherit ROOM;
void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
�������ϴ���ϣ����ż�ʵ����ʯ����档�����Ե����ֶ��ˡ�
���������Ƕ���֣�����һֱ�߶����ϴ�֡����Ϸ������������֣�
�����и��͵ꡣ
LONG
        );

        set("exits", ([
                "west" : __DIR__"sroad2",
                "southeast":__DIR__"kezhan",
                "northeast":__DIR__"eroad2s",
                ]));
         set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
