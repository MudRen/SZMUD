//Cracked by Roath
// helper.c ���͵�����
// Long, 6/13/97
// This NPC will help newbie with ling once a yeat to steal, or rob
//      back special items such as yitian-jian,...
// He will also will try to revenage the death of a newbie with ling.
//      he will only do that if the newbie was killed for no reason.
//      if the newbie was killed because he started the fight, or steal,
//      or try to steal from other player, then he won't revenage for him.

#include <ansi.h>

inherit NPC;
object home;
object helpee;
object ling;
int do_return(object ling, object whom);
int do_valify_find(object me);
int do_finished(object item);
int do_steal(object item, object whom, int count);
int do_find(string arg);
int do_kill();
int checking(object);
int do_back(object);
int waiting(object);
int do_killing(object, object);
int do_chase(object);
int ask_ling();
string* items = ({
//Special weapons
        "/clone/weapon/yitian-jian",
        "/clone/unique/xuantie-jian",
        "/clone/unique/yuchang-jian",
        "/clone/unique/xuedao",
        "/clone/unique/eweibian", 
        "/clone/unique/eyujian", 
        "/clone/unique/jinshe-jian", 
        "/clone/unique/xiangmo-chu", 
        "/clone/unique/youlong", 
        "/clone/unique/yuzhu-zhang", 
        "/clone/unique/yuxiao", 
        "/clone/unique/fumo-dao", 
//Special armors
        "/d/taohua/obj/ruanwei-jia",
//      "/d/shenlong/obj/jinlu-yi",
        "/d/shaolin/obj/jingang-zhao",
        "/d/xueshan/obj/wucan-yi", 
//Special Books
        "/d/huashan/obj/zixia_book",
        "/d/huashan/obj/jinshe_book2", 
        "/d/city/npc/obj/shenzhao", 
});

string* itemnames = ({
        "���콣",
        "������",
        "�㳦��",
        "Ѫ��",
        "��β��",
        "�����",
        "���߽�",
        "��ħ��",
        "������",
        "������",
        "����",
        "��ħ��",
        "��⫼�",
//      "������",
        "�����",
        "�ڲ���",
        "��ϼ�ؼ�",
        "�����ؼ�",
        "���վ�",
});

void create()
{	switch (random(3)) 
        {
		case 0:
	      	set_name("���", ({ "yu fu", "fu"}));
      	  	set("long", "
������ȥ���ƽƽ������������ͳ���ı۰�ɹ�úںڵġ�
��ֻҪ�����ģ���ͷ����������������������һ�ѳ�����\n");
                  break;
		case 1:
			set_name("����", ({ "shang ren", "trader"}));
			set("long", "
������ȥ�������ͭ�������ˣ���ķ��֣�������ⱦ���ġ�
��ֻҪ�����ģ���ͷ����������������������һ�ѳ�����\n");
	  		break;
		case 2:
			set_name("����", ({ "shu sheng", "sheng"}));
			set("long", "
������ȥ����䲴����������ͷ���Ե�һ������ӵ����ӡ�
��ֻҪ�����ģ���ͷ����������������������һ�ѳ�����\n");
	  		break;
	}

        set("gender", "����");
        set("age", random(40) + 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("race", "����");    
        set("max_qi", 1500);
        set("eff_qi", 1500);
        set("qi", 1500);
        set("max_jing", 1500);
        set("eff_jing", 1500);
        set("jing", 1500);
        set("max_neili", 1500);
        set("eff_neili", 1500);
        set("neili", 1500);
        set("max_jingli", 1500);
        set("eff_jingli", 1500);
        set("jingli", 1500);
        set("combat_exp", 500000 + random(5) * 100000);
        set("score", 1000);
        
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 150);
        set_skill("sword", 150);
        set_skill("taixuan-gong", 150);
        set_skill("liuxing-bu", 150);
        set_skill("wugou-jianfa", 150);
        set_skill("stealing", 150);
        set_skill("wuyu-zhangfa", 150);

        map_skill("force", "taixuan-gong");
        map_skill("sword", "wugou-jianfa");
        map_skill("parry", "wugou-jianfa");
        map_skill("dodge", "liuxing-bu");
        map_skill("strike", "wuyu-zhangfa");
        prepare_skill("strike", "wuyu-zhangfa");
	  set("chat_chance", 5);
        set("chat_msg", ({
		(: random_move :),
		}));
        set("inquiry", ([
                        "���͵�"   :  "���������͵��ĵ��ӣ�����ʲ������Ҫ�����ģ�",
                        "������"   :  "��Ҫ������ʲ����صĶ�������������Ļ��ҿ��԰���㡣\n",
                        "������"   :  "��Ҫ����ʲ��Ѫ���޷������з�����Ļ��ҿ��԰���㡣\n",
				"����"     :  (:ask_ling, ling:),
                ]));
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/yellowrobe")->wear();

}

void init()
{
        add_action("do_find", "��");
        add_action("do_find", "find");  
        add_action("do_kill", "ɱ");  
        add_action("do_kill", "����");  
}
int ask_ling()
{	object me = this_player();
	object ling1;
	object ling2;
	object *lings;
	object holder, holdee;
	int count, flag;
	if ((ling1 = present("shangshan ling", me)) && (ling2 = present("fae ling")))
	{	return 0;
	}
	if (query_temp("xkd/busy"))
      {     command("say ����æ���أ�����ɡ�");
      	return 1;
	}

	if ((!ling1) && (me->query("xkd/find") == 0))
	{	lings = children("shangshan ling");
		flag = 0;
		if (lings)
		{	for (count = 0; count < sizeof(lings); count ++)
			{	if (lings[count]->query("owner") == me->query("id"))
				{	holder = environment(lings[count]);
					if ( holder->is_container())
					{	holdee = environment(holder);
	        			}
					else
					{	holdee = holder;
					}
					command("say ���" + lings[count]->query("name")+"��"+holdee->query("name")+"�ǣ���ȥ�û����ɡ�");
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{	ling1 = new("/d/xiakedao/obj/shan-ling.c");
			ling1->move(this_object());
			ling1->set("long", 
"����һ�����ƣ��Ƶ�һ����һ��Ц������һ����š�" + me->query("name") + "��\n");
			ling1->set("owner", me->query("id"));
			command("say �ðɣ����ٸ���һ"+ling1->query("unit") + ling1->query("name")+ ", ��ο�Ҫ�պ��");
			command("give "+ ling1->query("id") + " to " + me->query("id"));
		}
	}
	else
	{	if (!ling1)
		{	command("say ���Ѿ���" + ling1->query("name") + "�������ˣ���Ȼ�Ҳ����ˡ�");}
	}
	if ((!ling2) && (me->query("xkd/kill") == 0))
	{	lings = children("fae ling");
		flag = 0;
		if (lings)
		{	for (count = 0; count < sizeof(lings); count ++)
			{	if (lings[count]->query("owner") == me->query("id"))
				{	holder = environment(lings[count]);
					if ( holder->is_container())
					{	holdee = environment(holder);
	        			}
					else
					{	holdee = holder;
					}
					flag = 1;
					command("say ���" + lings[count]->query("name")+"��"+holdee->query("name")+"�ǣ���ȥ�û����ɡ�");
				}
			}
		}
		if (flag == 0)
		{	ling2 = new("/d/xiakedao/obj/fa-ling.c");
			ling2->move(this_object());
			ling2->set("long", 
"����һ�����ƣ��Ƶ�һ����һ����������һ����š�" + me->query("name") + "��\n");
			ling2->set("owner", me->query("id"));
			command("say �ðɣ����ٸ���һ" +ling2->query("unit") + ling2->query("name")+ ", ��ο�Ҫ�պ��");
			command("give "+ ling2->query("id") + " to " + me->query("id"));
		}
	}
	else
	{	if (!ling2)
		{	command("say ���Ѿ���" + ling2->query("name") + "�������ˣ���Ȼ�Ҳ����ˡ�");}
	}

	return 1;
}
int item_num(string item)
{       int i = 0;
        while (i < sizeof(items))
        {       if (itemnames[i] == item)
                {       return i;
                }
                i = i + 1;
        }
        return -1;
}
int accept_object(object who, object ob)
{       object me = this_object();
        if (query_temp("xkd/busy"))
        {       command("say ����æ���أ�����ɡ�");
                return 0;
        }
        if ((ob->query("id") != "fae ling") && (ob->query("id") != "shangshan ling"))
        {       return 0;       }
        if (ob->query("owner") != who->query("id"))
        {       command("shake " + who->query("id"));
                command("say �㲻����" + ob->query("name") + "�����ˣ��Ҳ��ܰ��㡣");
                return 0;
        }
        if ((int)who->query("combat_exp") < 10000)
        {	    if (ob->query("id") == "shangshan ling")
		    {	   command("say С������������صĶ���������һ�������ɡ�");}
		    else
		    {	   command("say С����ѧ�˴��ɱɱ�ĸ��");}
                return 0;
        }
        ling = ob;
	  helpee = who;
	  this_object()->set_temp("xkd/busy", 1);
        if (ob->query("id") == "shangshan ling")
        {	who->set_temp("xkd/give", 1);
		command("say ������ʲ���ء�(find)");

        }
        else
        {	who->set_temp("xkd/give2", 1);
		command("say �����ȷ��Ҫ���𣬾͸����Ұɡ�(����)");
        }
        return 1;
}
#include "/d/xiakedao/npc/helpfind.h"
#include "/d/xiakedao/npc/helpkill.h"