// smiling_room.c �����鹤����
// by April 01/08/09

inherit ROOM;

void create()
{
        set("short", "�����鹤����");
        set("long", 
				"���Ǽ�޴�ľ���ι����ң��ӵ��浽�컨�嶼�������...��...����ֽ��\n"
				+"���������и�����δ���(��β�Ͳ�����)���������������һֻδ�깤������\n"
				+"��צ�Ĵ�����(��)��������ʦ����ɨ�������Ҵ�(�е�����׷��Ĳ�Ӭ)��Ϊ��\n"
				+"��������������ڹ�����Ŀǰ�������ڱ�д��Ĺ�ɣ�����:\n\n"
				+"��ڤ��(scatter)����дskills \n"
				+"ʫܰ(jiuer),	 ���Ƶ����� \n"
				+"�ڱ�(blacko),	 Э��jiuer \n"
				+"����(lara),	���� \n"
				+"�����(Fengyu),	���� \n"
				+"���ٰ���(chchong),	��Ů�ľ���exert,skills���� \n"
				+"Ҷ��(lisser),		skills���� \n"
				+"���(april)��	 ��Ů�ľ������������exert \n\n"
				+"�����ְ�ܽ�أ��鲽��̫�գ�����ҷ�����������ɺ硣�� \n\n"
				+"�����ȳ���ϣ�����������! \n"
				+"��ӭ�������۾��� \n\n"
			);

        set("exits", ([
                "east" : __DIR__"meeting_room",
                 ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();

        call_other("/clone/board/menpai_b", "???");
//      replace_program(ROOM);
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
