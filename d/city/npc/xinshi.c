// Code of ShenZhou
// Write by Wzfeng 12-29 //main fuction
// modified by sdong, 12/29/98
// Change by Wzfeng, 3/1/98  // add ask jin nang

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
int ask_me();
int ask_jinnang();
void create()
{
                  set_name("��ة", ({ "yi cheng", "cheng" ,"cheng" }));
                  set("shen_type", 1);

                  set("gender", "����");
                  set("age", 45);
                  set("long",
"����ר�Ÿ��������麯���ݵĹ�Ա��\n"
);
                  set("attitude", "friendly");
                  set("inquiry", ([
                                "����" : (: ask_me :),
                                "send" : (: ask_me :),
								"����" : (:ask_jinnang :),
                  ]));

                  set("vendor_goods", ({
					  
                                __DIR__"obj/maobi",
                                __DIR__"obj/xinzhi",
                                __DIR__"obj/xinfeng",
                                __DIR__"obj/xinfeng1",
                                __DIR__"obj/xinfeng2",
                  }));
  

/*				   set("vendor_goods", ([
                __DIR__"obj/maobi":99,
                __DIR__"obj/xinzhi":99,
				__DIR__"obj/xinfeng":99,
				__DIR__"obj/xinfeng1":99,
				__DIR__"obj/xinfeng2":99,
              

                
        ]));
  */     
  
                  setup();

                 remove_call_out("do_check_letter");
                 call_out("do_check_letter", 3+random(10) );

}

void init()
{
         object ob;
         ob=this_object();
         add_action("do_list", "list");
         add_action("do_buy", "buy");
         add_action("do_send", "send");
         add_action("do_check_letter", "check");
}

int do_emote(string str)
{
        message_vision(CYN "$N�������֣�һ����ʹ���˹�����\n"NOR, this_object());
        message_vision(CYN "$N����ʹ˵�����������͸�"+str+"���麯���Ͽ���ȥ����Ҫʧ�䡣\n"NOR, this_object());
        message_vision(CYN "��ʹ���麯�ӹ�������źã���$N���ֵ�����С����ͳ�������\n"NOR, this_object());
        message_vision(CYN "��ʹǣ��һƥ��������Ծ�������ﳤ��ȥ......\n"NOR, this_object());
        return 1;
}

string query_letter_file( string arg)
{
         return sprintf( DATA_DIR "letter/%c/%s", arg[0], arg );
}

int do_check_letter()
{
                object *ob,ob_letter;
                 string file ;
                  int i;
                  ob=objects();
                  i = sizeof(ob);
                  while (i--)
                {
                        if (userp(ob[i]))
                        {

                                file = query_letter_file( ob[i]->query("id")+".o" );
                                assure_file( file );

                                if(file_size(file)!=-1)
                                {

                                        if(interactive(ob[i]))
                                        if(living(ob[i]))
                                        if(!ob[i]-> is_busy())
                                        if(!ob[i]-> is_fighting() )
                                        {
                                                ob_letter=new("/clone/misc/xin");
                                                ob_letter->set_owner(ob[i]->query("id"));
                                                ob_letter->check(ob[i],this_object());
                                        }
                                }
                        }
                }

          remove_call_out("do_check_letter");
          call_out("do_check_letter", 3+random(10) );

          return 1;
}





int ask_me()
{
        write("��ة����˵������Ҫ�����������ţ����Ƚ��麯��ã�Ȼ�󽻸��ҡ���\n"
                "���� send letter \n");
                return 1;
}
int do_send(string arg)
{
        object ob_letter,me,send_letter;

        int i;
        mapping letter;


        me=this_player();
        if(!arg) return notify_fail("��Ҫ����ʲô��\n");

        ob_letter = present(arg, me);
        if(!ob_letter)
                return notify_fail("�����Ϻ���û��������Ʒ��\n");
        if(!ob_letter->query("can_send"))
                return notify_fail("�Բ����������ﲻ�����������\n");
		if(me->is_busy())
			    return notify_fail("��������æ���ء�\n");

		letter=ob_letter->query("letter");
		
		send_letter=new("/clone/misc/xin");
		send_letter->set_owner(letter["to"]);
		
		//��ֹflood,���������ǰδ���������к����һ���ģ��;ܾ�������š�
		//////////////////////////////////////////////////////////////


			if((letter["from"]==send_letter->query("last_from"))&&
				(letter["text"]==send_letter->query("last_text")))
		  {
			  command("hmm ");
			  return notify_fail("���������Ҵ�����һ�����һ�����ź���������æ�úܣ������������ɡ�\n");
		  }
		//////////////////////////////////////////////////////////////		
		


        switch( ob_letter->query("letter/send_level"))
        {
                                case 1:
                                message_vision("$N�ӹ�$n�ݹ����ķ��ף�����һ�ۣ����ַ������׳����\n", this_object(),me);
                                                  break;
                                case 2:
                                message_vision(HIY"$N�ӹ�$n�ݹ����ļ�⣬����һ�ۣ���$n˵������������ã��һᾡ���ͳ��ġ���\n"NOR, this_object(),me);
                                                  break;
                                case 3:
                                message_vision(HIR"$N�ӹ�$n�ݹ����Ĳ��ף�һ��֮�£���æվ��������$n˵����������ʮ��𼱣������Ͻ���ȥ��������飡��\n"NOR, this_object(),me);
									                break;
                    
        }
		
		send_letter->add_send_level(ob_letter->query("letter/send_level"));
	
		//��������ǰ�İ汾�д�����������������������б���letter���ļ�
		//ɾ�����������ɾ�������򣬻������°ɡ�
		//////////////////////////////////////////////////////////////
		send_letter->set("can_send",0);
		send_letter->set("can_feng",0);
        //////////////////////////////////////////////////////////////
		
		
		send_letter->send_letter(letter);
		send_letter->set("last_from",letter["from"]);
        send_letter->set("last_text",letter["text"]);
		send_letter->save();

        destruct(send_letter);
		destruct(ob_letter);
		do_check_letter();
		me->start_busy(1);
		

        return 1;
}

int ask_jinnang()
{
	object ob,me;
	ob=this_object();
	me=this_player();

    
    if(me->query("have_jinnang"))
	if(present("jin nang", me))
	{
		tell_object(me,CYN"��ة����˵�������㲻���Ѿ���һ�����𣿡�\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,CYN"��ة����˵�������㲻���Ѿ���һ�����𣿡�\n"NOR);
		tell_object(me,CYN"��ة����˵������Ŷ��Ū���ˣ���\n"NOR);
		command("consider ");
		tell_object(me,CYN"��ة�����������˵��������ʮ�����������Ҿ��ٸ���һ������\n"NOR);
		me->set_temp("can_give_jinnang",1);
		return 1;
	}

	
	if(me->query_temp("can_give_jinnang"))
	{
		tell_object(me,CYN"��ة����˵�������Ҳ����Ѿ����������𣿡�\n"NOR);
		return 1;
	}
  
	
	message("vision", CYN "ֻ��"+me->query("name")+"����ة�������ĵ�˵�˼��仰��\n" NOR, environment(me), me);
  	tell_object(me,CYN"������ة��������˵�������ܰ��Ҹ��װ�ŵĽ���ô����\n"NOR);
	command("ah");
	tell_object(me,CYN"��ة�����������˵����������Ҫһ��װ�ŵĽ��ң���\n"NOR);
    tell_object(me,CYN"��ة�����������˵��������������ޱȣ�ʮ������һ���������ۣ���\n"NOR);
	message("vision", CYN "ֻ����ة��"+me->query("name")+"�������ĵ�˵�˼��仰��\n" NOR, environment(me), me);
    me->set_temp("can_give_jinnang",1);
	
	return 1;
  
}

int accept_object(object who, object ob)
{
	int value;
	object ob1,money,Ob_JinNang;
	ob1=this_object();
	if(!who->query_temp("can_give_jinnang"))
	{
		command("? "+who->query("id"));
		return 0;
	}
	if(!ob->query("base_value"))
	{
		command("? "+who->query("id"));
		write("!ob->query(value)\n");
		return 0;
	}
       switch( ob->query("id"))
        {
		   case "gold":
                value=1000;
				  break;
		  case "silver":
    			value=100;
				  break;
		   case "coin":
    			value=10;
				  break;
		   default:
			   {
			   	   command("shake "+who->query("id"));
				   write("��ة����˵�������Բ��������ﲻ����Ʊ�����õ����̻����������ɣ���\n");
						return 0;			   
			   }
        }


	value*= ob->query_amount();


	if(value<10000)
	{
		command("shake "+who->query("id"));
		tell_object(who,CYN"��ة����˵��������˵����ʮ���ƽ���Щ���ﹻ����\n"NOR);
		return 0;
	}


	command("nod "+who->query("id"));
	tell_object(who,CYN"��ة����˵��������һ�����ң���С���պá���\n"NOR);
	write("��ة����һ�����ҡ�\n");
	who->set("have_jinnang",1);

	Ob_JinNang=new("/clone/misc/jinnang");
	Ob_JinNang->move(who);


	return 1;
	
}



