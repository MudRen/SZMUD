// Code of ShenZhou
// publisher.c
// by snowbird 1999
// modified a little by sdong, 10/20/1999


#define BOOKTOOL  "/d/city/obj/booktool"
#define SHUFANG   "/d/city/shufang"
#include <ansi.h>
#include <localtime.h>

inherit NPC;
inherit F_SKILL;
inherit F_SAVE;
inherit F_UNIQUE;

int ask_book();
int ask_sell();
string ask_chore();
void check_book();
void enough_rest();
void clear_book();


string is_vendor_good(string arg);
string query_book_file( string arg);

mapping *sell_list;

string query_save_file()
{
                  return "/data/npc/publisher";
}


void create()
{
        set_name("���ϰ�", ({ "wang laoban", "publisher", "wang"}));
	set_color(YEL);
	set("long", "����һλ�װ����ֵ������ˣ�����΢΢�������Ǹ����̺���ģ����\n"
	"����������һ��С���ӣ���Ц���е����´������㡣\n"
        "��˵�������Թ��ƾ٣������β��к������Է���Ϊҵ�ˡ�\n");
	set("gender", "����");
	set("age", 45);
    set("weight", 50000);
    set("str", 25);
    set("dex", 25);
	set("attitude", "peaceful");

    set("combat_exp", 75000);
    set("shen_type", 0);

    set_skill("unarmed", 60);
    set_skill("force", 60);
    set_skill("literate", 300);

    set("neili", 4000); 
    set("max_neili", 4000);
    set("jiali", 500);

    set("owner", 1);
    set("no_clean_up", 1);

    set("inquiry", ([
	    "profit" : (: ask_book :),
	    "chore" : (: ask_chore :),
	    "����" : (: ask_chore :),
	    "���" : "������������ȱ��������,��˵��Щ�쳤�ְ������˹�������.",
	]));

    set("vendor_goods", ({
                                        
		  "/d/city/obj/newbook1",
    }));

//    set("chat_chance", 3);
//	set("chat_msg",({
//               (: check_book :),
//    }));

 
    if(!restore())
	{
		setup();
	}

    carry_object("/d/city/obj/guazi")->wear();

    remove_call_out("check_book");
    call_out("check_book", 3+random(5) );

}


int init()
{
  object ob;
  ob = this_player();
  ::init();

  add_action("do_list", "list");
  add_action("do_buy", "buy");
  add_action("do_publish","publish");
  add_action("do_discard","discard");

  if( interactive(ob = this_player()) && !is_fighting() ) {
       remove_call_out("greeting");
       call_out("greeting", 1, ob);
  }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision(	"$N��$n΢΢Ц��Ц��\n",this_object(),ob );
        switch( random(2) ) {
                case 0:
                        command( "say ��λ" + RANK_D->query_respect(ob)
                                + "����Ҫ������������������Ҷ����ˡ�\n");
                        break;
                case 1:
                        command( "say ��λ" + RANK_D->query_respect(ob)
                                + "�������и��ֽ�����ʿд�ı�¼����������Ҫ����һ����\n");
                        break;
        }
}


int do_publish(string arg)
{
	object me, this_book, save_book;
    mapping book_content;

    if(!arg) return notify_fail("��Ҫ����ʲô��\n");

	me = this_player();
    this_book = present(arg, me);

    if(!this_book)
            return notify_fail("�����Ϻ���û������������\n");
    if(!this_book->query("publishable"))
            return notify_fail("�Բ��������������޷���ӡ��\n");
    if(me->is_busy())
            return notify_fail("��������æ���ء�\n");



// get the book content 
    book_content=this_book->query("book_content");
// stamp on time, number of book sold, money made and the marker not to discard it
// also set the initial price to be 20 silver
	book_content["publish_time"] = ctime(time());
	book_content["book_sold"] = 0;
	book_content["money_made"] = 0;
	book_content["keep_marker"] = 0;
	book_content["current_price"] = 2000;
    save_book=new("/clone/misc/save_book");
    save_book->set_owner(book_content["arthur_id"]);
    save_book->save_this_book(book_content);
    message_vision(	"$N�߸����˵ذ�$nд�ĸ�ֽ��ȥ��ӡ�ˡ�\n\n",this_object(),me );

    destruct(save_book);
	destruct(this_book);

   remove_call_out("check_book");
   call_out("check_book", 1 );

    return 1;
}

int do_discard(string arg)
{
	object me;
    int book_no, value, val_factor, i, k, book_found;
    string ob_file, file;
    object ob, obj, *inv;

    if(!arg) return notify_fail("��Ҫ�ջ�ʲô��\n");

	me = this_player();

    if(me->is_busy())
            return notify_fail("��������æ���ء�\n");

        k = 0;
		book_found = 0;

		if( sscanf(arg, "book%d", book_no) == 1 ) 
		{
            inv = all_inventory(this_object());
			if(!sizeof(inv))
			    return notify_fail("�����ջصĶ���������û�С�\n");
            for (i = 0; i < sizeof(inv); i++) 
	     	{
                if ( inv[i]->query("can_sell_book") )
				{
					k++;
    				if ( k == book_no ) {
					   ob = inv[i];
					   book_found = 1;
					   break;
					}
		 		}
		    }
			if (!book_found)
				return notify_fail("�����ջصĶ���������û�С�\n");
		}
		else 
		{
			return notify_fail("�����ջصĶ���������û�С�\n");
        }

		
        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

		if( (ob->query("new_book"))["arthur_id"] != me->query("id") && !wizardp(me) )
			return notify_fail("���ֲ������ˡ�\n");

	    message_vision(	"$N����$n�����" +(ob->query("new_book"))["arthur"] + "д��"+(ob->query("new_book"))["title"]+"�������ȡ���ˡ�\n\n",
		this_object(),me );

        obj=new("/clone/misc/save_book");
        obj->set_owner((ob->query("new_book"))["arthur_id"]);
        obj->discard_book((ob->query("new_book"))["title"]);

		destruct(obj);
		destruct(ob);

    return 1;
}

int do_list()
{
        string *goods, long_name;
        object *inv;
        int i, j, k;

		remove_call_out("check_book");
		call_out("check_book", 0 );

        inv = all_inventory(this_object());
		k = 0;
        if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
                return notify_fail("Ŀǰû�п�����Ķ�����\n");
        // list the cloneable goods
        if (arrayp(goods = query("vendor_goods"))){
                for (i = 0; i < sizeof(goods); i++)
                        printf("%65-s��%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        }
		// list the inventory for sell
        for (i = 0; i < sizeof(inv); i++) 
		{
                if (inv[i]->query("can_sell_book"))
				{
					k++;
					long_name = sprintf("%s(%s%d)",(inv[i]->query("new_book"))["title"],inv[i]->query("id"),k);
                    printf("%35-s �����ߡ�%20-s ��%s\n", long_name, 
                    (inv[i]->query("new_book"))["arthur"],MONEY_D->price_str(inv[i]->query("value")));
				}
		}
        return 1;
}       

int do_buy(string arg)
{
        int book_no, value, val_factor, i, k, book_found;
        string ob_file, file;
        object ob, obj, *inv,soldbook;


        k = 0;
		book_found = 0;
        if (!arg)
                return notify_fail("������ʲô��\n");
        if (ob && ob->query("money_id"))
                return notify_fail("������Ǯ������\n");

		if (arg == "book")
		{
		    ob_file = is_vendor_good(arg);
			ob = new(ob_file);
			val_factor = 10;
		}
		else if( sscanf(arg, "book%d", book_no) == 1 ) 
		{
            inv = all_inventory(this_object());
			if(!sizeof(inv))
			    return notify_fail("������Ķ���������û�С�\n");
            for (i = 0; i < sizeof(inv); i++) 
	     	{
                if (inv[i]->query("can_sell_book"))
				{
					k++;
    				if ( k == book_no ) {
					   ob = inv[i];
					   book_found = 1;
					}
		 		}
		    }
			if (!book_found)
				return notify_fail("������Ķ���������û�С�\n");
		}
		else 
		{
			return notify_fail("������Ķ���������û�С�\n");
        }

		
        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
				

        
  switch (MONEY_D->player_pay(this_player(), ob->query("value") )) {
        case 0:
                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
        default:
                set_temp("busy", 1);
                message_vision("$N��$n����������һ" + ob->query("unit") + 
                ob->query("name") + "��\n", this_player(), this_object());
				// save the number of book sold and money made to file
				if(book_found) {
                   obj=new("/clone/misc/save_book");
                   obj->set_owner((ob->query("new_book"))["arthur_id"]);
                   obj->save_book_sold(ob->query("book_number"),ob->query("value")/2);
 				   //soldbook = obj->get_new_book();
				   destruct(obj);
				}
                //soldbook->move(this_player());
				ob->move(this_player());
        }
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}

string is_vendor_good(string arg)
{
        string *goods;
        object ob;
        int i;

        if (arrayp(goods = query("vendor_goods"))) 
                for (i = 0; i < sizeof(goods); i++) 
                        if (goods[i]->id(arg))
                                return goods[i];
        return "";
}

void enough_rest()
{
        delete_temp("busy");
}

string query_book_file( string arg)
{
         return sprintf( DATA_DIR "book/%c/%s", arg[0], arg );
}

void check_book()
{

   string *dir_list, *time_list;
   string file, arthur_id, time_lable; 
   object new_book, real_book, *inv, temp_book;
   mixed *file_list;
   int i, j, k, l, call_time;
   mapping book_info;
   mixed *local;
   object me = this_object();

   // get our local time first
   local = localtime(time()*60);

   if (!(me->query("last_clear_book_time"))) {
	  // this is the first time we clearing the book
	  // record the current year
	  me->set("last_clear_book_time",local[LT_YEAR]);
   }
   else {
	  // we have recorded a time before, so let's check if we need
	  // to clear the books
	  if ((local[LT_YEAR] - me->query("last_clear_book_time")) == 1) {
		  // ok one year has passed, time to clear the books
		  // first set our new clear book time
          set_temp("busy", 1);
	      me->set("last_clear_book_time",local[LT_YEAR]);
		  clear_book();
          delete_temp("busy");
	  }
	  else {
		  // if the time is messed up, refresh our count
    	  me->set("last_clear_book_time",local[LT_YEAR]);
	  }
   }

   time_list = ({});
   k = 0;
   inv = all_inventory(this_object());
   if (!sizeof(inv))
       k = 0;
   else {
	  // build my book time list
	  for (i = 0; i<sizeof(inv); i++) {
		 if ( inv[i]->query("can_sell_book") ) {
		   time_list += ({ inv[i]->query("time_stamp") });
		   k++;
		 }
	  }
      // if the there are 40 books, get ride one of them, randomly
      if (k>399) {
	      l = random(sizeof(inv));
		  if ( inv[l]->query("can_sell_book") ) {
			 temp_book = inv[l];
 			 time_list -= ({ inv[l]->query("time_stamp") });
			 destruct(temp_book);
		  }
      }
   }

   // if publisher have 20 book in his invertory, slow down checking for new books
   if (k<20) 
	  call_time = 10;
   else
      call_time = 360;

   //  get my random arthur
   dir_list = explode("a b c d e f g h i j k l m n o p q r s t u v w x y z", " ");
   //   dir_list = explode ("a s"," ");
   //i = random(26);
   for(i=0;i<26;i++)
   {
	file_list = get_dir(DATA_DIR + "book/" + dir_list[i] + "/");
	// if no file, then exit
	if (!sizeof(file_list)) {
		  // do nothing here
	}
	else {
		//  j = random(sizeof(file_list));
		for(j=0;j<sizeof(file_list);j++)
		{

		sscanf(file_list[j], "%s.o", arthur_id);
        
		file = query_book_file( arthur_id+".o" );
		assure_file( file );

	      if(file_size(file)!=-1)  {

		      new_book=new("/clone/misc/save_book");
			  new_book->set_owner(arthur_id);

 			  real_book = new_book->get_new_book();

			  if( !objectp(real_book) )continue;

			time_lable = real_book->query("time_stamp");
			// if this time_stamp is not the same as something in invertory then get it
			// if there are already 30 books in his inventory, don't create anymore
			if ( member_array(time_lable, time_list) == -1 && k<400) {
				  real_book->set("can_sell_book",1);
				real_book->move(this_object());
			}
			else {
				destruct(real_book);
			}
		}
      destruct(new_book);
		}
	}
   }

   remove_call_out("check_book");
   call_out("check_book", call_time+random(3) );

}

int ask_book()
{
   object me, new_book;
   string file, arthur_id;
   me=this_player();

   arthur_id = me->query("id");
   file = query_book_file( arthur_id+".o" );
   assure_file( file );

   if(file_size(file)!=-1)  {
          new_book=new("/clone/misc/save_book");
          new_book->set_owner(arthur_id);
		  new_book->pay_player_profit();
   }
   else {
        return notify_fail("�㻹δ���г�һ���飬����ҪǮ��\n");
   }

   destruct(new_book);
   return 1;
}



void clear_book() 
{

   string *dir_list;
   string file, arthur_id; 
   object new_book, *inv, temp_book;
   mixed *file_list;
   int i, j, k, l;

   dir_list = explode("a b c d e f g h i j k l m n o p q r s t u v w x y z", " ");
   for (i=0; i<26; i++) {
      file_list = get_dir(DATA_DIR + "book/" + dir_list[i] + "/");
      if (!sizeof(file_list)) {
    	 // do nothing here
      }
      else {
         k = sizeof(file_list);
		 for (j=0; j<k; j++) {
            sscanf(file_list[j], "%s.o", arthur_id);
            file = query_book_file( arthur_id+".o" );
            assure_file( file );

            if(file_size(file)!=-1)  {
               new_book=new("/clone/misc/save_book");
               new_book->set_owner(arthur_id);
			   new_book->clear_book();
			}
		 }
      }
   }
   destruct(new_book);
   return;
}

string ask_chore()
{
 object me=this_player();
 object ling,obj;
 if( (string)me->query_temp("bangs/fam") != "���ְ�" )
                return RANK_D->query_respect(me)+"���ǳ��ְ����ˣ�����������ݡ�";
 
 if( !(ling = present("bang ling", me)) )
                return RANK_D->query_respect(me)+"����ӡ��û�У�����������������㡣";
 
 if (ling->query("job/type")!="���")
                return RANK_D->query_respect(me)+"���²�û�б�ָ�����˴�����ɡ�";

 if (me->query_skill("literate",1)<10)
 {              ling->delete("job/name");
                return RANK_D->query_respect(me)+"���Ļ�ˮƽ̫�Ϳ����޷�ʤ��������Ĳ��£����ǻ�ȥ�ɡ�";
 }
 command("ok");
 obj=new(BOOKTOOL);
 obj->set("owner",me->query("id"));
 
 message_vision( "$N��$n˵��������������ȱ������Ļ�ƣ������ҵ�����ȥ�鷿�ɡ�\n",this_object(),me );
 message_vision( "$N����ó�һ��"+HIW"�ķ��ı�"NOR+"����$n��������һλ���״�$n�����鷿��\n",this_object(),me );
 obj->move(me);
 me->move(SHUFANG);
 return "�úøɰɣ�";
}
