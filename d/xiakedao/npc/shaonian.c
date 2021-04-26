//Cracked by Roath
// shaoniao.c ���͵�����
// Long, 6/13/97
// Ssy

#include <ansi.h>

inherit NPC;

int ask_me(string, object);
void greeting(object);

void create()
{
	set_name("����", ({ "shao nian", "nian", "man"}));
	set("long", "������ȥ�����ͨ��ũ���ӵܣ�����ȥ�ǳ��Ľ�ʵ��\n");
	set("gender", "����");
	set("age", 18);
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
	set("combat_exp", 10000);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("cuff", 20);
	set_skill("sword", 20);
	
	set("inquiry", ([
			"��ԭ"   :  (: ask_me, "leave" :),
			"����"   : 	"�������Ͷ����ޡ�\n",
			"����"   :  (: ask_me, "exp" :),
			"���"   :  (: ask_me, "fight" :),
			"�Ȼ�"   :  (: ask_me, "fight" :),
			"ɱ��"   :  (: ask_me, "kill" :),
			"Ǳ��"   :  (: ask_me, "pot" :),
                        "������ƴ"   :  (: ask_me, "kill" :),
		]));
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
{	
	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("hi " + me->query("id"));
		command("say 
          ��λ" + RANK_D->query_respect(me) + 
                   "�Ǹ����İɡ���ӽ����������ճ�����������
    ����Ͷ��ȥ�����������������ʲô���ʣ��������Ұɡ�����˵
    ʲ����"+HBRED+HIW"����"NOR+"��"+HBRED+HIW"Ǳ��"NOR +"�����"+HBRED+HIW"���"NOR+"�ȵȡ�");
		me->set_temp(this_object()->query("id"), 1);
	}
}
int ask_me(string name, object ob)
{
     if ( name == "exp" )
       {
	 command("say 
          ��ľ���ߵ;���������书���ܵĸߵ͡��ȷ�˵����� 
    ������ 1000���㼼�����ֻ�ܵ� 22: (22-1)^3 / 10 < 1000��
    ���˱Ȼ�������Խ��ʤ��Ҳ��Խ�ߡ��þ�����򵥵ķ����Ǻͷ� 
    ��ң��ΣУã���ܡ��ΣУõľ�������������̫�����ǵ�
��������ʲ�ᾭ��ġ�������֪��һ���ΣУ��ǲ����ʺ��㣬����Ҫ
��������������ҡ�����Щ�����þ���ķ��������Ÿ��ɶ��в�ͬ��
��������������ʦ�֣�ʦ������̰ɡ�");
	 return 1;
       }
     else if ( name == "fight")
       {	
	 command("say 
          ��������֣�һ���ǱȻ�(fight)����һ����������ƴ(kill)
    ���Ȼ�ʱ����ľ�������ʧ����ʱ����ͻ�����ͣ�֡�����ʱ��
   �ֻ᲻�����Ȼ����������Ҫ��֮���֣���ֻ����kill�ˡ����
   ��������ƴ��Σ�գ��Է���ɱ�����ǲ���ͣ�ֵġ�Ϊ�˰�ȫ�����
   �԰��������ָ�����(set wimpy 60)��60��ʾ����ľ���������
   ���ٷ�֮��ʮ����ͻ��Զ����ܡ�����ʱ���ֵĹ���̫ǿ����ʽ̫
   �������㻹�ǻ��Ӳ����ġ��������˲���ʱҪ�ر�С�ġ��������
   ���ұȻ������á�fight man���������ҵľ���ֵ�ܸߵ�ม�");
	 return 1;
       }
     else if ( name == "leave")
       {	
	 say("����ҡ��ҡͷ˵����û�е���ͬ�⣬��ɲ���˽���뵺��");
	 return 1;
       }
     else if ( name == "kill")
       {	
	 command("say 
         �����Ҫ��ɱ˭��������ã���졣ɱ����Щʱ��Ҫ����
   Щ���۵ġ���Ҫ���ڳ���ɱ��ң��ᱻ�ٸ�ͨ������Ҫ��ɱ�˸���
   ����ͷ�����ģΣУã��ٸ�Ҳ��ͨ����ġ���ͨ�����ˣ�Ѳ������
   ͷ���ٱ����佫�ȼ��˶���׷ɱ�ġ���Ҫ�Ǳ���ɱ��Ҳ����̫�ѹ�
   ����ֻ����Щ����ͼ��ܡ����ڽ�������һ������ɱ���ˣ�������
   һ��û�б�ɱ����һ����˵��������ڶ�ʮ��ǰ������������ʮ��
   �ͺܲ����ˡ������мǣ������͵��Ͽɲ���ɱ�ˣ�ɱ��������");
	 return 1;
       }
     else if ( name == "pot")
       {
	 command("say 
         Ǳ����������ʦ��ѧ����ġ�ÿ��ʦ��ѧһ�Σ�����Ҫ��һ
   ��Ǳ�ܡ���Ǳ�ܵ���򵥷����;���һ�����ͣΣУô�ܡ�Ҳ�;�
   ��һ����ֻ�к����㹦������ģΣУô�ܲ��ܵ�Ǳ�ܡ�����Щ��
   ����Ǳ�ܵķ��������Ÿ��ɶ��в�ͬ�ķ���������ʦ�֣�ʦ������
   �̰ɡ�(help learn)");
	 return 1;
       }
}

