//Cracked by Yujie
// forest/clbajiaoting.c
// by 9 / 2001

inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
�����ǳ��ְ����᷿�����������˾ͽ������ʦֶʯ�������
��֮����������������ˣ�������������������Ը��������κ���
���˵�ǰ��ɧ�š�
LONG );

        set("exits", ([
		"out" :  __DIR__"clbajiaoting",
        ]));
        set("objects", ([
                "/kungfu/class/misc/dingdang.c" : 1,
                        ]));
                        
        set("cost", 0);
        set("no_fight",1);
        set("no_steal", 1);

        setup();

        replace_program(ROOM);
}
