//Room: /d/kaifeng/guangchang.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "����㳡");
        set("long", @LONG
�����ǿ��⸮ǰ�㳡���ÿտ��ĵط���ֻ��ϡϡ���伸��û����
�ɵ����ˡ�������ǿ��⸮�ˣ��ϱ��ǿ���֡��㳡��Χ����һȦ��
�������������԰�����㳡����ɹ�ù���ð�̡�
LONG
        );

        set("exits", ([
                "west" : __DIR__"wroad1",
                "east":__DIR__"eroad1",
                "south":__DIR__"sroad1",
                "north":__DIR__"fumen",
        ]));

       set("objects",([__DIR__"npc/wujiang":1,]));
       set("outdoors", "kaifeng");
       setup(); 
       replace_program(ROOM); 
       }
