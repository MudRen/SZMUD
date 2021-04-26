// Code of ShenZhou
// d/quanzhou/leitai.c ������̨;
inherit ROOM;

void create()
{
        set("short", "������̨");
        set("long", @LONG
����һ����ʵ׳�۵���̨����̨��Լ���࣬�����Լ�����ɷ�Բ��ȫ����
�ڴֵ�ľͷ��ɡ�̨���ǽ������һ���������㣬���ư���Ĵ��֡����䡹��
��̨ǰ�����ĺ�ֻ����(sign)���չ�����б�����˶�������������ý���
��֪�������еĺ����ǳ��ڴ��д���ԣ������˶϶�ԩ����Ȼ��ʱҲ�н�����
Ů���ˡ��������ס������ϲ�£�����һ�����ּѻ���
LONG
        );
        
	set("exits", ([
		"south" : __DIR__"enyuan",
	]));

	set("item_desc", ([
		"sign" : "����ָ�dagu [zhaoqin(marryfight)|qiecuo(fight)|juezhan(kill)] <sb>\n\n"
			"����ֻ����������(zhaoqin)���д����(qiecuo)��������ս(juezhan)���á�\n" 
			"�������ˣ������Ը�����\n",
	]));

	set("no_death", 1);

	set("cost", 1);
        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_dagu", "dagu");
}

int do_dagu(string arg)
{
	object ob, me = this_player();
	string opp, str, event;

	if ( !arg ) return notify_fail("��Ҫ����ʲô��\n");

	if ( sscanf(arg, "%s %s", event, opp) != 2  ) return notify_fail("��Ҫ����ʲô��\n");

	if ( me->query("id") == opp ) return notify_fail("����ë������\n");

	if ( !present(opp, environment(me)) ) return notify_fail("���ﲢ�޴��ˣ�����Լ�������ɡ�\n");

	if ( !find_living(opp) ) return notify_fail("��������������ǲ��ǻ��\n");

	if ( event == "marryfight" || event == "zhaoqin" ) {
		if ( me->query("gender") == "����" )
		     	return notify_fail("���Ⱳ�ӱ�ָ���ˣ�\n");
		else if ( me->query("class") == "bonze" )
			return notify_fail("�㷲��δ��������������\n");
                else if ( me->query("gender") == "����" )
                        return notify_fail("Ψ��Ů�����ܾ��б������ף�\n");
		else str = "��������";
	}
	else if ( event == "fight" || event == "qiecuo" ) {
		str = "�д����";
	}
	else if ( event == "kill" || event == "juezhan" ) {
		str = "������ս";
	}
	else return notify_fail("����ֻ����������(zhaoqin)���д����(qiecuo)��������ս(juezhan)���á�\n"); 

	ob = find_player(opp);

	message_vision("$N�����鳣����˴��һ�£���ķ������̡���һ�����죬������Զ��\n", me);
	CHANNEL_D->do_channel(me,"rumor",sprintf("%s�����鳣����˴��һ�£���ķ������̡���һ�����죬������Զ��", me->name()));
	CHANNEL_D->do_channel(me,"chat",sprintf("��������%s����̨����%s�����λ����ͬ��������֤��", ob->name(), str));

	return 1;
}

