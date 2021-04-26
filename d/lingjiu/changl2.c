//room: changlang2.c
/*Updated by George 98/7
	1. sword to 30;
	2. tianyu-qijian to 30;
*/

inherit ROOM;

int do_wujian();

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ��(hua)���������ɣ�����ʤ�գ��ƺ���𴦲�ͬ����
�岻֪����ʲô�������ģ��������������Ϣ����ֻ�е���������ģ�
�ǳ����������ͨ�������
LONG
    );

  set("item_desc",([
	  "hua"	:	"����һ��������������Ůͼ��������Ů�ֳֳ���(wujian)�������������������衣\n",])
	 );

  set("exits",([
      "east" : __DIR__"changl3",
      "west" : __DIR__"huayuan",
     ]));

 setup();
// replace_program(ROOM);
}

void init()
{
	add_action("do_wujian", "wujian");
}

int do_wujian()
{
	mapping fam; 
	object ob, weapon;

	ob = this_player();

	if (!objectp(weapon = ob->query_temp("weapon"))					//must wield jian first
	|| (string)weapon->query("skill_type") != "sword")				
		return notify_fail("��ʹ�õ��������ԡ�\n");
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;
	}

	if ((int)ob->query_skill("sword", 1) < 30) 
    {
			
		if( (int)ob->query_skill("sword", 1)* (int)ob->query_skill("sword", 1) * (int)ob->query_skill("sword", 1)/ 10 > (int)ob->query("combat_exp") ) {
			write("Ҳ����ȱ��ʵս���飬��Ի��е��⾳�����޷���ᡣ\n");
			return 1;
		}
		ob->receive_damage("jing",30, "����������");
		ob->improve_skill("sword", ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;
	}
	else if((int)ob->query_skill("tianyu-qijian",1)>30)
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;
	}
	else{
		ob->receive_damage("jing",30, "����������");
		ob->improve_skill("tianyu-qijian",ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;

	}

	return 1;
}