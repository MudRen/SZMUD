// a skeleton for user rooms

inherit ROOM;

void create()
{
	set("short", "�һ���");
	
	set("long", @LONG
    ����һƬ�������һ��ԣ���ɽ��Ұ������֦�ϣ������Һ����
�����һ���ͷ��������ϸϸ���˵Ĳ��ʼ�į���۷䡣������һ����
��Ҳ��խ���ּ�С�������������ܴԴԵ��۲ݺ����涷�޵�С����
LONG
);
	set("exits", ([
		"south" : "/d/taohuacun/taohua6.c",
		]));
	
	set("objects", ([
       		]) );
	
	set("owner", "xuanyuan");
	set("class", "�������С�");
	set("valid_startroom",1);
	set("no_fight",1);

setup();
}
void init()
{
	add_action("do_invite","invite");
	//add_action("do_setowner","setowner");
}
int valid_enter(object me)
{
	int flag;
// always let owner go in:
	 if((string)me->query("class") != (string)query("class")
	&&(string)query("invite") != (string)me->query("id")
	&&(string)me->query("id") != (string)query("owner"))
	return 1;	

}
int do_invite(string arg)
{
	object me;
	me= this_player();
	if((string)me->query("id") != (string)query("owner"))
	return 0;
	set("invite",arg);
	write("������"+arg+"����ķ��䡣\n");
	return 1;
}

/*int do_setowner(string arg)
{
	string oldowner;
	oldowner = (string)query("owner");
	set("owner",arg);
	write("�㽫�����������ʱ��Ϊ"+arg+"��\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int set_back(string oldowner)
{
	set("owner", oldowner);
	return 1;
}
*/