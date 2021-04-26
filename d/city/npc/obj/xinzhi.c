// Code of ShenZhou
// Write by Wzfeng 12-29-1998
//change By Wzfeng 4/1/1999
#include <ansi.h>
inherit ITEM;
int  start_letter(object me);
void get_send_name(string username, object ob);
void get_letter_title(string str, mapping letter,object me);
void get_letter_text(mapping letter, string str);


void create()
{
	set_name("��ֽ", ({"paper"}));
	set_weight(10);
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ÿ���������ֽ����������д��(write letter)��\n");
		set("unit", "��");
		set("material", "paper");
		set("value", 10);
	}
}
int init()
{
    add_action("do_write", "write");
    
}


int do_write(string arg)
{
           object me,ob_bi,ob_paper;
           object ob_letter;
            me=this_player();
          	if (arg != "letter") 
				 return  notify_fail("��Ҫдʲô��\n");
          if(!ob_bi=present("mao bi",me))
                 return  notify_fail("�����û��д�ŵĹ��߰ɣ����ȥ��֧ë�ʣ�\n");
		  if (this_player()->is_busy())
				return notify_fail("����æ���أ������й���ʱ��д�ɡ�\n");

          message_vision("ֻ��$N�ó�һ֧ë�ʣ�չ����ֽ���ܱʼ���......\n"NOR,me);
          //destruct(ob_paper);
          start_letter(me);
          return 1;
        }

int start_letter(object me)
{
  tell_object(me,"�������ˡ�(Ӣ������):\n");
  input_to( (: get_send_name :), me );

}

void get_send_name(string username, object ob)
{
        mapping letter;
        object me;
        me=ob;
        ob = FINGER_D->acquire_login_ob(username);
        if( !ob ) {
                write("û������ˡ�\n");
          tell_object(this_player(),"�������ˡ�(Ӣ������):\n");
      input_to( (: get_send_name :),  me);
          return;
        }
        letter = ([
                "from": me->name(1) + "(" + me->query("id") + ")",
                "title": "�ޱ���",
                "to": username,
                "time": time(),
                "text": ""
        ]);
        write("�����ű��⡿:");
    input_to("get_letter_title", letter,me);
        
}


void get_letter_title(string str, mapping letter,object me)
{
        if( str!="" ) 
                letter["title"] = str;
        write("���������ݡ�:\n");
        me->edit( (: get_letter_text, letter:) );
}

void get_letter_text(mapping letter, string str)
{
        object ob_letter;
                
        
        letter["text"] = str;
        message_vision("ֻ��$N����һ��������ë�ʷŵ�һ�ԣ���д�õ��麯���������ڻ��\n"NOR,this_player());
        
		/*ob_letter=new("/clone/misc/xin");
        ob_letter->set_owner(letter["to"]);
		ob_letter->set("long", "һ���Ѿ�д�õ��ţ�����ö�(read letter)�����������ݡ�\n");
		ob_letter->set_name(HIW"��"NOR, ({"letter", "xin"}));
        ob_letter->set("can_feng",1);
		ob_letter->set("can_send",0);
		ob_letter->send_letter(letter);
		*/
		ob_letter=new("/d/city/obj/letter1");
		ob_letter->set("letter",letter);
		ob_letter->set("can_feng",1);
		ob_letter->set("can_send",0);
        ob_letter->move(this_player());
        destruct(this_object());
          return;
        
}







