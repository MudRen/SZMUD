//Room: /d/kaifeng/eroad2.c
// by bravo
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�����
�����سǹٱ���ߺ�����������ǿ��������Ǳ�һ���ྲ��ԭ������
Ϊ���⸮����ͷ���ϱ���һ����ֱ�Ĵ����
LONG
        );

        set("exits", ([
                "south" : __DIR__"eroad2s",
                "west":__DIR__"eroad1",
                "east":__DIR__"dongmen",
                ]));

       set("objects",([
         "d/city/npc/liumangtou":1,
        ]));

         set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}

