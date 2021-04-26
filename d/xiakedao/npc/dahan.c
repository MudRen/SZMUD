//Cracked by Roath
// dahan.c ���´�
// Long, 6/13/97
// xQin 7/00 cut sheyao

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_weapon();
int ask_armor();
void greeting(object);

string* armors = ({
        "/clone/armor/beixin",
        "/clone/armor/tie-beixin",
});

string* weapons = ({
        "/clone/weapon/caidao",
        "/clone/weapon/changjian",
        "/clone/weapon/duanjian",
});

void create()
{
        set_name("���´�", ({ "da han", "han"}));
        set("long", "����Ŀ��䣬����ȥ��һ��Сɽ�Ƶġ�\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("race", "����");    
        set("max_qi", 200);
        set("eff_qi", 200);
        set("qi", 200);
        set("max_jing", 200);
        set("eff_jing", 200);
        set("jing", 200);
        set("max_neili", 200);
        set("eff_neili", 200);
        set("neili", 200);
        set("max_jingli", 200);
        set("eff_jingli", 200);
        set("jingli", 200);
        set("combat_exp", 50000);
        set("score", 1000);

        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("cuff", 70);
        set_skill("sword", 70);
        
        set("inquiry", ([
                        "����"   :  (: ask_weapon :),
                        "����"   :  (: ask_armor :),
                        "��ԭ"   :      (: ask_leave :),
                        "����"   :      "���������ڶ��\n",
        "��"     :  "����û��ʲ����̡���ص���ԭʱҪʲ�ᶫ���ɵ�������\n",
        "��"     :  "����Ҳû�е��̡���ԭ�ļ���������е��̣�û�õĶ�������������\n",
                ]));
        set("armor_count", 50);
        set("weapon_count", 50);
        setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{       object sheyao;
        object weapon, armor;
        string whattosay;
        int count = 0, i;

        if (me->query_temp(this_object()->query("id")) == 0 )
        {       command(":) "+ me->query("id") );
                whattosay = 
"
             ��λ"+RANK_D->query_respect(me) + 
          "��ɽ·��Ұ·ʱҪС��Ұ�ޣ��ϻ��Ͷ���
     ���˾�ҧ�ġ���������ʯ�����֦������������ǿ��Ĺ�������
     �����������Щ������������Ƥ��ţƤ��Ƥ���ģ������׵ȵȣ�
     ��Щ������������ķ���������";
                command("say " + whattosay);
                me->set_temp(this_object()->query("id"), 1);
        }
        for( i = 0; i < sizeof(weapons); i++ )
        {       if (  weapon = present(weapons[i]->query("id"), me) )
                {       if (weapon->query("equipped") == 0)
                        {       command ("say" + RANK_D->query_respect(me) + "��������" + 
                                        weapon->query("name") + "װ�������ɡ�\n" +
                                        HBRED+HIW"(wield " + weapon->query("id") + ")"NOR + "��");
                        }
                        count = count + 1;
                }
        }
        if (count == 0 ) 
        {       command("say �����������м�����������Ҫ�Ļ��͸����ҡ�\n" + 
                HBRED+HIW"(ask han about ����)"NOR+ "��");
        }
        count = 0;
        for( i = 0; i < sizeof(armors); i++ )
        {       if (  armor = present(armors[i]->query("id"), me) )
                {       if (armor->query("equipped") == 0)
                        {       say("���´�˵����" + RANK_D->query_respect(me) + "��������" + 
                                        armor->query("name") + "װ�������ɡ�"+ 
                                        HBRED+HIW"(wear " + armor->query("id") + ")"NOR +"��\n");
                        }
                        count = count + 1;
                }
        }

	if (count == 0)
        {       command("say �������Ҳ����һ�������ߣ�Ҫ������Ҫ�ɡ�\n" +
                        HBRED+HIW"(ask han about ����)"NOR +"��");
        }
//        if (  present("she yao", me) )
//	{	say("���´�������üͷ˵�����Ͽ����Ҫ���¡�\n");
//	} 
//	else if (present("she yao", environment(me)))
//	{	say("���´�������üͷ˵�����Ͽ����Ҫ���¡�\n");
//	}
       // count = (int)me->query_condition("snake_poison");
       // if ( count > 0)
       // {       command("say ��ѽ���㱻����ҧ�ˣ�����������Щ��ҩ������°ɡ�\n" +
         //       HBRED+HIW"(fu sheyao)"NOR);
          //      count = count / 5 + 1;
           //     for (i = 0; i < count; i++ )
             //   {       
			//	sheyao = new("/clone/drug/sheyao.c");
			//	sheyao->move(this_object());
//		command("give " + sheyao->query("id") + " to " + me->query("id"));
//                }
//        }
}
int ask_leave()
{       
        say("���´�ҡ��ҡͷ˵����û�е���ͬ�⣬��ɲ���˽���뵺��\n");
        return 1;
}
int ask_weapon()
{       int i;
        object you = this_player();
        object weapon;
        if (query("weapon_count") < 1)
        {       say("���´󺺵�ͷ�����Ϸ��˰��죬��Ǹ��Ц��Ц˵�����Բ���û�ˡ�\n");
                return 1;
        }
        
        for( i = 1; i < sizeof(weapons); i++ )
        {       if (  present(weapons[i]->query("id"), you) )
                {       say("���´�������üͷ˵�������˻�Ҫ����̫̰���˰ɡ�\n");
                        return 1;
                }
                else if (present(weapons[i]->query("id"), environment(you)))
                {       say("���´�������һָ�����ϲ���������Ҫ�Ļ��ͼ��߰ɡ�\n");
                        return 1;
                }
        }
        weapon = new(weapons[random(sizeof(weapons))] );
        weapon->set("value", 0);
        weapon->move(this_object());
//      command("say " + weapon->query("id") + " to " + you->query("id"));
        command("give " + weapon->query("id") + " to " + you->query("id"));
//      say("���´󺺴������ҳ�һ" + weapon->query("unit") + weapon->query("name") + "�����˸��㡣\n");
//      weapon->move(you);
        add("weapon_count", -1);
        return 1;
}
int ask_armor()
{       int i;
        object you = this_player();
        object armor;
        if (query("armor_count") < 1)
        {       say("���´󺺵�ͷ�����Ϸ��˰��죬��Ǹ��Ц��Ц˵�����Բ���û�ˡ�\n");
                return 1;
        }
        for( i = 1; i < sizeof(armors); i++ )
        {       if (  present(armors[i]->query("id"), you) )
                {       say("���´�������üͷ˵�������˻�Ҫ����̫̰���˰ɡ�\n");
                        return 1;
                }
                else if (present(armors[i]->query("id"), environment(you)))
                {       say("���´�������һָ�����ϲ���������Ҫ�Ļ��ͼ��߰ɡ�\n");
                        return 1;
                }
        }
        armor = new( armors[random(sizeof(armors))] );
        armor->move(this_object());
        armor->set("value", 0);
        command("give " + armor->query("id") + " to " + you->query("id"));
        }
