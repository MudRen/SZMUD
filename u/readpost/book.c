// Code of ShenZhou
#include <ansi.h>
inherit ITEM;


int start_book_title(object me);
void get_book_title(string book_title, object ob);
int start_book_text(object me, int p_no);
void get_book_text(string str, int p_no);
int help(object me);

mapping new_book = ([]);
mapping text = ([]);
// text = allocate( string 20 );

void create()
{
        set_name("ֽ��", ({"book"}));
        set_weight(10);
      set("no_steal", 1);
      set("no_sell", 1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���հ׵��飬�����������д�֡�(write)\n");
                set("unit", "��");
                set("material", "paper");
                set("value", 100000);
        }
}
int init()
{
    add_action("do_title","title");
    add_action("do_write", "write");
    add_action("do_read", "read");   
}

int do_title(string arg)
{
          object me;
          object this_book;

          me = this_player();
		  this_book = this_object();

          if (arg != "book") 
              return  notify_fail("��Ҫдʲô��\n");

          if(!this_book->query("titled"))
 		  {
              start_book_title(me);
		  }
		  else {
              message_vision("$N�������룬�־���Ҫ��������һ�ġ�\n"NOR,me);
			  start_book_title(me);
		  }

		  return 1;

}

int start_book_title(object me)
{
    tell_object(me,"��������:");
    input_to( (: get_book_title :), me );
	return 1;
}

void get_book_title(string book_title, object ob)
{
        object me, this_book;

        me=ob;
		this_book = this_object();

        if( !book_title || (strlen(book_title)<2) ) {
              write("����д������\n");
              tell_object(this_player(),"��������:");
              input_to( (: get_book_title :),  me);
              return;
        }

        message_vision("$N���˰��죬�����ڷ�Ƥ������һ��������\n"NOR,me);
        book_title="��"+book_title+"��";
	new_book["title"] = book_title;
        new_book["arthur"] = me->name(1) + "(" + me->query("id") + ")";
        new_book["arthur_id"] = me->query("id");
 
        this_book->set("titled",1);
        this_book->set_name(book_title, ({"book"}));
		this_book->set("long", "һ��δд����飬��������������д��(write book)\n");
        this_book->set("book_content",new_book);

        return;        
}

int do_write(string arg)
{
          string msg;
          object me;
          object this_book;
		  int page_no;

          me = this_player();
		  this_book = this_object();

	      if( !arg || sscanf(arg, "%s %d", msg, page_no)!=2 ) return help(me);

          if (msg != "page") 
              return  notify_fail("д���� (write page #) ��\n");
		  if (page_no > 20 || page_no < 1) 
              return  notify_fail("д���� 1 �� 20 ҳ֮�䡣\n");
          if(!this_book->query("titled"))
		      return  notify_fail("�㻹û�и��������أ������������˵�� (title book)��\n");
		  else 
		  {
              message_vision("$N�ó�һ֧�ʣ��̿��鱾����ʼд��.....\n"NOR,me);
			  start_book_text(me, page_no);
		  }
          return 1;

}


int start_book_text(object me, int p_no)
{
        write("���鱾���ݡ�:\n");
        me->edit( (: get_book_text, p_no :) );
        return 1;
}

void get_book_text(int p_no, string str)
{

        message_vision("$Nд��һ�Σ��������еıʡ�\n"NOR,this_player());
   		text[p_no] = str;
        new_book["text"] = text;


        this_object()->set("book_content",new_book);
        this_object()->set("text_written",1);
        this_object()->set("publishable",1);
        return;
        
}

int do_read(string arg)
{
        string msg, this_page;
		int page_no;
		object me, this_book;

        me = this_player();
		this_book = this_object();

        if( !arg || sscanf(arg, "%s %d", msg, page_no)!=2 ) return help(me);

        if (msg != "page") 
             return  notify_fail("������ (read page #) ��\n");
    	if (page_no > 20) 
              return  notify_fail("�鲻���� 20 ҳ��\n");

        if(!this_book->query("text_written"))
             return  notify_fail("�Ȿ�黹ûд����ô����\n");

        if(!(this_page = new_book["text"][page_no]))
             return  notify_fail("��һҳ��ûд����ô����\n");;

        printf("��%s����\n�����ߡ���%s\n\n",
		new_book["title"],new_book["arthur"]);
		this_player()->start_more(this_page);

        
        return 1;
}

int help(object me)
{
	write("ָ���ʽ��\n
	д���� (write page #) ��\n
	������ (read page #) ��\n");
	return 1;
}
