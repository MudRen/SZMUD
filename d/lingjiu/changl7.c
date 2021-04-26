//room: changl7.c
/*Update by George 98/7
	1.	strike to 30;
	2.	liuyang-zhang to 30;
*/

inherit ROOM;

int do_strike();

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
	  "hua"	:	"����һ��������������Ůͼ��������Ů���������裬�ƺ���������һ���Ʒ�(strike)��\n",])
	 );

  set("exits",([
      "east" : __DIR__"changl15",
      "west" : __DIR__"changl6",
     ]));

 setup();
// replace_program(ROOM);
}

void init()
{
	add_action("do_strike", "strike");
}

int do_strike()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮�����㵸��\n");
		return 1;
	}

	if ((int)ob->query_skill("strike", 1) < 30) 
    {
			
		if( (int)ob->query_skill("strike", 1)* (int)ob->query_skill("strike", 1) * (int)ob->query_skill("strike", 1)/ 10 > (int)ob->query("combat_exp") ) {
			write("Ҳ����ȱ��ʵս���飬��Ի��е��⾳�����޷���ᡣ\n");
			return 1;
		}
		ob->receive_damage("jing", 10);
		ob->improve_skill("strike", ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮�����㵸��\n");
		return 1;
	}
	else if((int)ob->query_skill("liuyang-zhang",1)>30)
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮�����㵸��\n");
		return 1;
	}
	else{
		ob->receive_damage("jing",10);
		ob->improve_skill("liuyang-zhang",ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮�����㵸��\n");
		return 1;

	}

	return 1;
}