//Room: /d/kaifeng/sroad2.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
�������ڿ��⸮���ϴ���ϣ�����һ���������Ĵ�·��һֱ��
�������졣·�����������������ò����֡�һЩС��С������������
ЩС���������������ţ�����һ��������п���֣���һ����֪��Ϊ
ɶ���ᰲ���ˡ�
LONG
        );

        set("exits", ([
                
                "east":__DIR__"sroad2e",
                "west":__DIR__"sroad2w",
                "south":__DIR__"nanmen",
                "north":__DIR__"sroad1",
        ]));

           set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
