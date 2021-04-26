//room: changl1.c
/*Update by George 98/7
	1. hand to 30;
	2. zhemei-shou to 30;
*/

inherit ROOM;

int do_zhemei();

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
	  "hua"	:	"����һ��������������Ůͼ��������Ů�ֳ�һ֦��÷(zhemei)�����������衣\n",])
	 );

  set("exits",([
      "west" : __DIR__"changl5",
      "east" : __DIR__"huayuan",
     ]));

 setup();
 //replace_program(ROOM);
}

void init()
{
	add_action("do_zhemei", "zhemei");
}

int do_zhemei()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;
	}

	if ((int)ob->query_skill("hand", 1) < 30) 
    {
			
		if( (int)ob->query_skill("hand", 1)* (int)ob->query_skill("hand", 1) * (int)ob->query_skill("hand", 1)/ 10 > (int)ob->query("combat_exp") ) {
			write("Ҳ����ȱ��ʵս���飬��Ի��е��⾳�����޷���ᡣ\n");
			return 1;
		}
		ob->receive_damage("jing",30, "����������");
		ob->improve_skill("hand", ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;
	}
	else if((int)ob->query_skill("zhemei-shou",1)>30)
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;
	}
	else{
		ob->receive_damage("jing",30, "����������");
		ob->improve_skill("zhemei-shou",ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮�������衣\n");
		return 1;

	}

	return 1;
}