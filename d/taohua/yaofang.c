// Code of ShenZhou
//Kane

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
�����ǻ�ҩʦ����ƽ������ҩ�ĵĵط����һ�������Ҳ������������ȡ��
һЩ�Լ����õ�ҩ�ɢ�������������ķλ���ľ����һ����������µľŻ�
��¶�裬��ζ�̱ǵ����ǽⶾ��ҩ�����赨ɢ����ɫ�ɺ���Ѫ��������ʥҩ��
������������һ�����ȡ�
LONG
	);
	 set("exits", ([
                "north" : __DIR__"changlang2",
        ]));
        
	set("objects", ([
                __DIR__"npc/mianfeng" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "�һ���") && dir == "north" )
                return notify_fail("�һ���������ͣ��㲻��ס�����\n");

        if ( me->query("gender") == "����" && dir == "north" )
                return notify_fail("�㲻��ס�����\n");

        return ::valid_leave(me, dir);
}
*/
