//Room: /d/kaifeng/sroad1.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����־�����Ϊͨ�����⸮����������һ���������˺��٣�����
��ľ͸��Ǿ����ˡ������˺����������벻���ģ����˺ö������
�����������������ﶼ��������̤�롣
LONG
        );

        set("exits", ([
                
                "south":__DIR__"sroad2",
                "north":__DIR__"guangchang",
        ]));

           set("outdoors", "kaifeng");
         set("objects",([
           __DIR__"/npc/bing":2,
         ]));
        setup();
        replace_program(ROOM);
}
