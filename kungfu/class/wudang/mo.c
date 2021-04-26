// Code of ShenZhou
// shenggu.c Ī����
// xQin 6/2000
// UPDATE BY SCATTER
// 1/9/2002

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void init();
int accept_object(object who, object ob);

string ask_me();
int ask_zwz();
string ask_me1();
int ask_me2();

void create()
{
        set_name("Ī����", ({ "mo shenggu", "mo", "shenggu" }));
        set("nickname", "�䵱����");
        set("long",
                "�������������С�ĵ���Ī���ȡ�\n"
                "�����ױ������ϳɣ�Ƣ���ֺ�ֱˬ�����ÿ�����ΰ��������Ũ�ݡ�\n"
                "�书������ޡ������һ��\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);
        set("combat_exp", 700000);
        set("score", 700000);
        set("wudang/raozhi", 1);

        set_skill("force", 185);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 160);
        set_skill("tiyunzong",  160);
        set_skill("cuff", 150);
        set_skill("strike", 150);
        set_skill("mian-zhang",150);
        set_skill("parry", 150);
        set_skill("sword", 185);
        set_skill("taiji-jian", 170);
        set_skill("throwing", 150);
        set_skill("literate", 120);
        set_skill("taoism", 120);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "chang-quan");
        prepare_skill("strike", "mian-zhang");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("sword.raozhi") :),
        }) );

        create_family("�䵱��", 2, "����");

                set("inquiry", ([
                "��ָ�ὣ" : (: ask_me :),
                "������" : (: ask_me1 :),
                "raozhi" : (: ask_me :),
                "qingshu" : (: ask_me1 :),
                "teach" : (: ask_me2 :),
                "ָ��" : (: ask_me2 :),
                                "�����߽���" : (: ask_zwz :),
                               
        ]));

        set("chat_chance",6);
        set("chat_msg", ({
            "Ī����˵��: ��֪�������ϵ�����Ϊʲô���������һ���䵱������\n",
            "Ī����˵��: ��Ϊ�䵱����Ӧʱʱ������Ϊ�ȣ���Ҫ�мǰ���\n",
            "Ī����˵��: ��Ϊ����֮�������Լ��ú�������ɡ� \n",        
            "Ī����˵��: �����Ǹ�������֪������ȥ�ˣ��ϴ��ڶ����治Ӧ�������ӵ��� \n"           
            "Ī����˵��: �´��ټ�������һ���������������ˡ� \n",        
        }));


        set("first_ask", 1);
        set("set_gocatch", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

        
void init()
{
        object ob;
        object me = this_player();
        
        ::init();
        
        if(present("qingshu", environment(me))) {
        command("sigh qingshu");
        call_out("qingshustory", 1, ob);
        
}
        
        
        if( interactive(ob = this_player()) && ob->query("family/family_name") == "�䵱��" )
                call_out("greeting", 1, ob);
}


void greeting(object me)
{
        command("nod " + me->query("id"));
}

string ask_me()
{
        mapping fam; 
        object me, ob, *obs;
        me = this_player();

        
                                
        if (me->query("can_fight", 1)) 
                {
                add_action("do_fight", "fight");
                command ("ok");
                me->delete("can_fight");
                me->set("fight_mo", 1);
                command("fight " + me->query("id"));
                return "��Ȼ�����ץ���˱�����ͽ�����ҿ�����Ե��������������������ְɡ�";
                }
        
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                { 
                command ("brother2");                   
                return RANK_D->query_respect(this_player()) + 
                "����Ҫ�������䵱�ɣ�";
                }       
                
        if (query("first_ask") < 1)
                {
                command ("smile");      
                return "����ָ�ὣ�������䵱�ɵľ���";
                }
        
        add("first_ask", -1);
        me->set("know_raozhi", 1);
        command ("hehe");
              return "��·����ָ�ὣ��ȫ���Ի���������佣�У�ʹ������˸�޳����������Ե��ܡ�";

        
}



string ask_me1()
{
        mapping fam; 
        object me, ob, qingshu, *obs;
        me = this_player();
        
                      
        
         if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
               { 
                command ("hmm");                
                return RANK_D->query_respect(this_player()) + 
                "�� ���������ʲô��ϵ��";
                }       
        
        
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                { 
                command ("hmm");                
                return RANK_D->query_respect(this_player()) + 
                "�� �벻Ҫ�����Ǹ�������";
                }       
                
        if (query("set_gocatch") < 1)
                {
                command ("hmm");        
                return "�Ҳ����������Ǹ�������";
                }
        
        add("set_gocatch", -1);
        me->set("set_gocatch", 1);
        command ("sigh ");
        return "�ϴβ�С�ı��Ǹ����������ˣ�����ʦ�Ų��ҡ�ֻ��ϧ�Դ��ϴ��ڶ��ұ������ߺ�һֱ�Ҳ�������";

        
}


int do_fight(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
  if (me->query("fight_mo", 1))   
  {       

      message_vision(HIR "������Ī������ɱ��$N��\n"NOR, me);
      tell_object(me,HIR "�����Ҫ��Ī���������ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
      fight_ob(this_player());
      add_action("do_halt", "halt");    
      add_action("do_brother2", "brother2");
      add_action("do_kill", "kill");
      me->delete("fight_mo");
      me->set("brother2_mo", 1);
      me->set("halt_mo", 1);
      
      return 1;
    }

}

int do_halt()
{
  object ob, obj=this_object();
  
  ob = this_player();
        
  
  if ( ob->query("halt_mo", 1) )
    {
      
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      command("sigh"); 
      command("halt");
      command("say ��Ȼ��ˣ����߰ɡ� ��û��ʲô�ý���ġ�");

      

 
  return 1;
}       
}


int do_kill(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
        
  if ((string)(me->query("family/family_name")) == "�䵱��" 
      && ob->query("id") == "mo shenggu" )
    {
      message_vision("$N��ɱ��$n��\n"
                     "$n������$N�������ұ�ͬ�ţ�ȴΪ�����຦���ң�\n"
                     "$n������$N�����������ѧ������ָ�ὣ����\n"
                     "$n��$N�ܲ����⣡\n" , me,ob);
      command ("sigh");
      command ("disapp");
      
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      me->delete("can_fight");       
      me->add("wudang/offerring", -20);
      return 0;    

}
}

int do_brother2(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
   if (me->query("brother2_mo", 1)) 
        
    {
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      me->delete("can_fight");
      me->set("can_teach", 1);   
      
      
      command ("say ��Ϊ�䵱���ӣ���������Ϊ�ȣ������������������ղ�����");
      command ("say ���ѵ����Ĵ����ʵ��������ˣ�ϣ�������Ϊ֮�����䵱������");
      command ("halt");
      command ("touch");
      command ("thumb");
      
      return 0; 
}
}
int accept_object(object who, object ob)
{
        object obn;

        
        if ( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0; 
        if ( !present(ob, who) ) return notify_fail("��û�����������");
        if (who->query("know_raozhi") < 1) 
        return notify_fail("����ô������Ū�������ˣ�");
        if (who->query("set_gocatch") < 1) 
        return notify_fail("�����ʲô��");
        if (  (string)ob->query("name") == "qingshu"
                || (string)ob->query("name") == "������"  ) 
        {
                if ( (string)ob->query("name") == "������" )
        {               
        who->delete("set_gocatch");
        who->add("can_fight", 1);
        who->add("wudang/offerring", 10);
        command ("thumb");
        command("touch " + (string)who->query("id")); 
        command("say " + RANK_D->query_respect(who)
                + "лл�����ץ���������ͽ�� \n");
        call_out("destroy_npc", 0, ob);
                }
        return 1;
        }
        command("? " + who->query("id"));
        
        
        return 0;
}

void destroy_npc(object ob)
{
        if( ob )  destruct(ob);
}

int ask_me2()
{
        mapping fam; 
        object me, ob, qingshu, *obs;
        me = this_player();
             
        if ((int)me->query("can_teach", 1) < 1)
        {
                command ("hmm");
                command ("say �������ʲô��");
                return 1;
                }
        if ((int)me->query_skill("sword", 1) < 180)     
        {
                me->delete("can_teach");
                command ("hmm");        
                command ("say ��Ľ�������̫ǳ��������ѧ����ָ�ὣ��");
                return 1;
                }
        
        if ((int)me->query_skill("force", 1) < 180)     
        {
                me->delete("can_teach");
                command ("hmm");        
                command ("say ����ڹ����̫ǳ��������ѧ����ָ�ὣ��");
                return 1;
                }

        me->set("wudang/raozhi", 1); 
        me->add("wudang/offerring", 10);        
        me->delete("can_teach");
        command ("ok");
        command ("say ���֪��Ʒ��������ģ�����Ҫѧ�ҾͰѡ���ָ�ὣ����������ɣ�\n");
        tell_object(me, HIW  "��ϲ��ѧ���ˡ���ָ�ὣ����\n" NOR);                       
        return 1;
     }



// FOLLOWING CODE ARE FOR ZHNWU 7 JIE ZHEN QUEST

int ask_zwz()
{
        object me = this_player();

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say ���ǲ���ѧ���ǲ��ǣ�");
                                return 1;
                }
                if ( me->query("zhenwu/7x") )
                {
                                command("say ���Ѿ���������Ҫѧ���顣");
                                return 1;
                }
        if ( me->query("combat_exp") < 100000 )
                {
                                command("say ���ʵս���黹���㣬������ò�Ҫѧ�������߽��󡹡�");
                return 1;
                }
        if ( me->query_skill("taiji-shengong", 1) < 100 )
                {
                                command("say ����ڹ�������������ѧ�������߽��󡹶���ٺ�����һ�棬�Ժ���˵�ɡ�");
                                return 1;
                }
        if ( me->query_skill("taoism", 1) < 100 )
                {
                                command("say ��Ե�ѧ�ķ��������˽⣬�����㲻����ᡸ�����߽��󡹵����⡣");
                                return 1;
                }
        if ( me->query("int") < 20 )
                {
                                command("say ������Բ����ߣ��������������߽��󡹵��������ڡ�");
                                return 1;
                }
        if ( me->query("max_neili") < 1000 )
                {
                                command("say ��������������ã���ȥ��û��������Ұɣ�");
                                return 1;
                }
        if ( me->query_skill("parry") < 100 )
                {
                                command("say �䵱�ľ�ѧ��������˸գ�����һ�㶫�����мܲ�ס����ôѧ�������߽��󡹣�");
                                return 1;
                }
                if ( me->query("jing") < 300 )
                {
                                command("say �����ڹ���ƣ�ͣ���ȥ��Ϣһ�°ɡ�");
                                return 1;
                }
        if ( me->query("jingli") < 2000 )
                {
                                command("say ��ϰ�������߽��󡹲���һ��������£��ҿ��������ڵ����������ʺ�����");
                                return 1;
                }
		if ( me->query("neili") < 2000)
		{
			command("say ��ϰ�������߽��󡹲���һ��������£������ڵ����������ʺ�����");
			return 1;
		}

                command("say �������ѧ��");
                write(HIY"��ѧ�Ļ���� xiang\n"NOR);
                me->set_temp("zhenwu/asking", 1);

                add_action("do_xiang", "xiang");
        
                return 1;

}

int do_xiang(string arg)
{
        object me = this_player();

                command("say �ðɣ��Ҿʹ����㡸�����߽��󡹵ĵ��߸�λ�ã��������Ƿ�������Ϳ�����ˡ�");
        command("say �����ร�");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}


void stepone(object me)
{
        command("say ���ȴ�����ھ���");
        message_vision(HIG"Ī���������˽�������֮���������˽�����ͻȻ������Ī����һ����Х�������䡣\nĪ������ָ�ڽ���������һ����ֻ���ó�����������֮�죬����ͣ������\n"NOR, me);
        message_vision(HIY"Ī����˳������һ���������������ջأ��������ջص��\n"NOR, me);
        command("say �㿴������");

		message_vision(NOR"$N������ĥ��Ī�������ڵ���Ҫ����\n"NOR, me);
        call_out("steptwo",8,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(200);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 130)
        {
				message_vision(HIR"$NͻȻһ����ѣ����ǰ��һ���ƺ����ڴ�ת����\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
				message_vision(HIC"$N�����󷨣��鶯�糤�ߣ��������ڹ꣬���󷨴�������\n"NOR, me);
                me->set("zhenwu/7x", 1);
                return;
        }
}
