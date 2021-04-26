// Code of ShenZhou
// du.h for fight and apprentice Du
//modified by xiaojian for not attacking outside fmq on Nov18,2000

#include <ansi.h>

void init()
{
  object me, ob, room1, room2;
  mapping fam;
  string name;

  me = this_player();
  ob = this_object();
  name = this_player()->query("name") ;

  if(!( room1 = find_object("/d/shaolin/fumoquan")) );
  room1 = load_object("/d/shaolin/fumoquan");

  if(!( room2 = find_object("/d/shaolin/dmyuan2")) );
  room2 = load_object("/d/shaolin/dmyuan2");

  ::init();
  if( interactive(me) ) 
    {
      if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
	   && fam["generation"] <= 37 && (name[0..1] == "��" || name[0..1] == "��")) {
	me->set_temp("fighter", 1);
	return;
      }
 
      if ( me->query_temp("calling") )
	{
	  if( environment(me) == room1 && present(me, room1) ) {
	    say(ob->name() + "˵��������ô����������ʦ�ķԸ������Դ����������� �������ҹ���ȥ��\n");
	    message_vision("$N˵������һ��һ�������ޱȵ���$nֱ���˳�ȥ��\n", ob, me);
	    call_out("move_out", 1, me);
	  }
	  else if( environment(me) == room2 && present(me, room2) ) {
	    message_vision("\nֻ����Ӱһ����һλ��ɮ��Ȼ������$N����ǰ������������ʲΪ��\n\n", me);
	    message_vision("$N������������$n�����˰��ã����˵�ͷ��˵���������Ϊʦ�ɲ����װ���\n" +
			   "���и���أ��������ֵ����߳�ʮ�еģ������ʸ������ǵ�ͽ�ܣ���Ը��Ļ���" +
			   "��˵(answer)һ����\n", ob, me);
	    me->delete_temp("calling");
	    me->set_temp("testing", 1);
	    add_action("do_say", "answer");
	    return;
	  }
	}
      else if( environment(me) == room2 && present(me, room2) ) return;

      if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
	   && fam["generation"] > 36               
	   && me->query("qi") < 50) 
	{
	  me->unconcious();
	  call_out("move_out", 1, me);
	  return;
	}
	//check condition to see if 3 du is in fmq or sjsz,if not,no attack
	//xiaojian
	  if(environment(ob) != room1 && strsrch(base_name(environment(me)),"/d/bwdh/sjsz")!= 0)
		  return;
      COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
      me->set_temp("fighter", 1);

      ob->fight_ob(me);
      me->fight_ob(ob);

      call_out("halt", 10);

      return;
    }
  return;
}

void debug(string s)
{
  // message_vision("debug $N: "+s+"\n", this_object());
}

int do_say(string arg)
{
  object me, ob;
  int i, count;

  me = this_player();
  ob = this_object();
		
  debug("do_say "+arg);
  if( !arg || arg=="" ) return 0;

  debug("checking args");
  if( arg=="Ը��" && me->query_temp("testing")) {

    debug("checking armor");
    if( this_player()->query_temp("apply/armor") >= 100 
	||  this_player()->query_temp("apply/damage") >= 100)
      return notify_fail("�ɶ�ҡͷ����������������ף����ܲμ����У�\n");

    message_vision("�ɶ���ͷ��˵�����ã��ҳ����ˣ�\n\n", me);

    for(i=0; i<10; i++) 
      {
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
	if( me->query("qi") >= 10 ) count++;
	else break;
      }

    if( count >= 7 ) {
      message_vision("\n�ɶ�Цһ����˵�����������Ǹ��ɽ�֮�ţ� �Ҿͳ�ȫ����ɣ�\n\n", me);
      me->set_temp("apprentice_ok", 1);
    }
    else    message_vision("\n�ɶ�Ц����С�������ɼΣ����ձ����������裬���ղ��ɣ����ӱ�Ŭ����\n\n", me);

    me->delete_temp("testing");

    call_out("leaving", 1, ob, 0, 900);

    return 1;
  }
}

int leaving(object ob, int time, int ready)
{       
  if ( time < ready ) {
    time = time + 100;
    call_out("leaving", 100, ob, time, ready);
    return 1;
  }
  else {
    message_vision( "$N���ͷ��˵�����˼������ˣ���ȥ�ˡ�\n" + 
		    "��˵�մ���ƮƮ���ﳤ������ֻһ�����ʧ���ټ���\n", ob);
    ob->move("/d/shaolin/fumoquan");
    return 1;
  }       
}

void attempt_apprentice(object ob)
{
  object me, zi; 
  mapping ob_fam, my_fam;
  string name, new_name;

  me = this_object();
  my_fam  = me->query("family");

  name = ob->query("name");

  if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
    {
      command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
      return;
    }

  if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
    {
      command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
      return;
    }

  if ( ob_fam["generation"] <= my_fam["generation"] )
    {
      command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
      return;
    }

  if ( ob_fam["generation"] == (my_fam["generation"] + 1) || name[0..1] == "��")
    {
      command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
      command("recruit " + ob->query("id"));
      return;
    }

  if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
    {
      if ( ob->query_temp("apprentice_ok") )
	{       
	  command("say ���İ���֮�䣬�ô��²����ˣ����ǿ�ϲ�ɺأ�");

	  name = ob->query("name");
	  new_name = "��" + name[2..3];
	  ob->set("name", new_name);
	  command("recruit " + ob->query("id"));
	  command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ�ʥɮ֮һ��");

	  if (!ob->query("shaolin/baidu_bonus")) {
	    ob->set("shaolin/baidu_bonus", 1);
	    command("say �������ľ�������Ħ���󷨣�Ϊ����̥���ǣ��ɾͽ���֮����");
	    message_vision(HIY "\n" + me->name() + 
			   "�ͺ�һ�������������У� ֻ��һ���������������Ʒɳ�����$Nͷ���������ѣ�����û�붥�ģ�\n" +
			   "$N��ʱ��ɫѪ�죬һ���ӵ����ڵأ���֫����������һ�ᣬ�Ž����ָ�ԭ״��վ��������\n\n" NOR, ob);

	    command("say �����ٸ������������ӣ�������������֮�ã�ע�ⲻ��һ��ȫ�����ã���������");
	    
	    ob->add("str",1);
	    ob->add("con",1);
	    ob->add("int",1);
	    ob->add("dex",1);
                   log_file("static/AddGift", sprintf("[%s]   %s   %s(%s)����Ϊ���������ֱ�ʥɮ�õ� ���������ԡ����ǡ�����һ�㡣\n",  
                           ctime(time())[0..15], me->query("family/family_name"), me->name(), getuid(me)));  
           me->add("AddGift/sl/dex",1);  
           me->add("AddGift/sl/int",1);  
           me->add("AddGift/sl/str",1);  
           me->add("AddGift/sl/con",1);  
			
	    zi=new(DRUG_D("puti-zi"));
	    zi->move(ob);
	    zi=new(DRUG_D("puti-zi"));
	    zi->move(ob);
	    zi=new(DRUG_D("puti-zi"));
	    zi->move(ob);
	  }

	  ob->delete_temp("apprentice_ok");

	  command("say ��ȥ�գ� ������ʲô���ѣ�������ʱ�������ǡ�");
	}
      else
	{
	  command("say " + RANK_D->query_respect(ob) + "��������ͽ���ϣ��㻹û���ʸ����ҵ�ͽ�ܡ�");
	  return;
	}
    }

  return;
}

string ask_damo()
{
  mapping fam, skill; 
  string *sname, name;
  object ob;
  int i, j;
	
  name = this_player()->query("name");

  if ( name[0..1] == "��" )
    return RANK_D->query_respect(this_player()) + 
      "���Ƕ��ֱ����ӣ��ο�����Ŀ������Ц��";

  if( this_player()->query_temp("win_times") >= 3 )
    return "�����ʦ�����ڹ�¥��������ʦ������������";

  if ( this_object()->query_temp("fighting") 
       ||   this_player()->query_temp("fighting") )
    return "�ϻ���̸����Ҫ�������ʦ�����͵ù���������һ�أ�";

  if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
    return RANK_D->query_respect(this_player()) + 
      "�����ִ��޹ϸ𣬲�֪�˻��Ӻ�̸��";

  if ( fam["generation"] != 36 )
    return RANK_D->query_respect(this_player()) + 
      "���ֲ��ϣ����ܼ�����ʦ����";

  if ( (int)this_player()->query("guilty") > 0 )
    return RANK_D->query_respect(this_player()) + 
      "���۷����䣬����������������ֱ����ҵ�ͬ�У�";

  skill = this_player()->query_skills();
  sname  = keys(skill);

  for(i=0; i<sizeof(skill); i++) {
    if ( skill[sname[i]] < 100 ) 
      return RANK_D->query_respect(this_player()) + 
	"�Ļ�������δ�ﾫ��֮�����ҿ��в����ʸ��������ʦ����";
  }

  for(i=0; i<sizeof(skill); i++) {
    if ( skill[sname[i]] >= 120 ) j++;
  }
  if ( j < 12 ) 
    return RANK_D->query_respect(this_player()) + 
      "��ĳЩ�书δ���ˣ��в����ʸ��������ʦ����";

  if ( skill["force"] < 150
       ||   skill["hunyuan-yiqi"] < 150            
       ||   skill["dodge"] < 150           
       ||   skill["shaolin-shenfa"] < 150          
       ||   skill["parry"] < 150 )         
    return RANK_D->query_respect(this_player()) + 
      "���;������书��ΪԶʤͬ�ţ������ٽ�һ���������¹�������������Ϊ��һ����";

  if ( (int)this_player()->query_skill("buddhism",1) < 150 )
    return "����ʦ�����Ͻ����" + RANK_D->query_respect(this_player()) + 
      "�ķ���Ϊδ֤������������̥�����޷�����ʦ���ġ�";
	
  ob=present("du nan", environment(this_object()));
  if( objectp(ob) )       ob->set_temp("fighting", 1);
  else    return "���Ѵ�ʦ���ڣ��㻹�ǵȻ������ɣ�";

  ob=present("du jie", environment(this_object()));
  if( objectp(ob) )       ob->set_temp("fighting", 1);
  else    return "�ɽٴ�ʦ���ڣ��㻹�ǵȻ������ɣ�";

  ob=present("du e", environment(this_object()));
  if( objectp(ob) )       ob->set_temp("fighting", 1);
  else    return "�ɶ��ʦ���ڣ��㻹�ǵȻ������ɣ�";

  this_player()->set_temp("fighting", 1);

  call_out("fighting", 600, this_player());

  return "�ã���־���¾��ɣ������������սʤ�������ˣ��Ҿ�ָ�����������ʦ����";
}

int fighting(object ob)
{
  return ob->delete_temp("fighting");
}

int accept_fight(object ob)
{
  object me  = this_object();
	
  if( ob->is_fighting() ) return 0;

  if ( !present("heilong bian", me) )
    return notify_fail( me->name() + "ҡͷ����������û�г��ֵı�������Ȼ���˵�ɣ�\n");

  if( ob->query_temp("apply/armor") >= 300 )
    return notify_fail(me->name() + "ҡͷ������������ף����ܲμ����У�\n");

  me->set("qi",      me->query("max_qi"));
  me->set("eff_qi",  me->query("max_qi"));
  me->set("jingli",  me->query("max_jingli"));
  me->set("jing",    me->query("max_jing"));
  me->set("eff_jing",me->query("max_jing"));
  me->set("neili",   me->query("max_neili"));

  me->delete("chat_msg_combat");

  if( !ob->query_temp("fighting") ) {
    if( me->query_temp("fighting") ) 
      return notify_fail( me->query("name") + 
			  "ҡͷ��������ս���������ϵ�ʱ���ѹ����´������԰ɡ�\n");
    else
      return notify_fail( me->query("name") + 
			  "ҡͷ��������Ե�޹���ƶɮ��ս���ƺ���Щʧ��ɣ�\n");
  }

  remove_call_out("checking");
  call_out("checking", 1, me, ob);
	
  return 1;
}

int checking(object me, object ob)
{
  object obj;
  int my_max_qi, his_max_qi;

  my_max_qi  = me->query("max_qi");
  his_max_qi = ob->query("max_qi");

  if (me->is_fighting()) 
    {
      call_out("checking", 2, me, ob);
      return 1;
    }

  if ( !present(ob, environment()) ) return 1; 

  if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
    {
      if( ob->query_temp("win_times") < 3 ) {
	command("say ��ʦ�书׿�����𷨸������������ʷ��������������ţ�\n");
	ob->add_temp("win_times", 1);
      }

      if( ob->query_temp("win_times") >= 3 ) {
	command("say �����ʦ�����ڹ�¥��������ʦ������������\n");
	ob->delete_temp("fighting");
      }
    }
  else if (( (int)ob->query("qi")*100 / his_max_qi) < 20 ) 
    {
      command("say " + RANK_D->query_respect(ob) + 
	      "����ѷ����һ���������ܰٳ߸�ͷ���ٽ�һ����ƾ�����Ϊ���ҵ�������ʦ�������������࣡\n");
      ob->delete_temp("fighting");
    }

  me->set("chat_msg_combat", ({
    (: auto_perform :),
      }) );

  return 1;  
}


private void move_out(object player)
{
  if(objectp(player) && environment(player) == this_object())
    player->move("/d/shaolin/qyping");
}
