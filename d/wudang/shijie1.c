//Cracked by Roath
// shijie1.c ʯ��
// by Xiang

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ�������
��������ɽ��������һ�����
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
                "northdown" : __DIR__"shanmen",
                "southup" : __DIR__"yuzhen",
	]));
	
	
    set("objects", ([
            __DIR__+"npc/guest" : 2 ]));
	            
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

