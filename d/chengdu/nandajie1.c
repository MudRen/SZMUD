// Room: /d/chengdu/nandajie1.c
// By Jpei

inherit ROOM;

void create()
{
        set("short", "�ᶽ��");
        set("long", @LONG
�ᶽ�־�����Ϊͨ���ᶽ������������һ���������˺��٣�����
��ľ͸��Ǿ����ˡ��ᶽ���˺����������벻���ģ����˺ö������
�����������������ﶼ��������̤�롣
LONG );
        set("outdoors", "chengdu");

	set("exits", ([
		"south" : __DIR__"nandajie2",
		"north" : __DIR__"center",
	]));
        set("objects", ([
            "/d/city/npc/bing" : 3,
        ]));

	setup();
	replace_program(ROOM);
}

