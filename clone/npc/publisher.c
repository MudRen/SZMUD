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
        set_name("王老板", ({ "wang laoban", "publisher", "wang"}));
	set_color(YEL);
	set("long", "这是一位白白胖胖的中年人，身子微微发福，是个富商豪绅模样。\n"
	"他手中提着一个小箱子，正笑眯眯地上下打量着你。\n"
        "据说他曾经试过科举，但几次不中后便改行以贩书为业了。\n");
	set("gender", "男性");
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
	    "当差" : (: ask_chore :),
	    "伙计" : "我们这里正好缺个抄书伙计,听说过些天长乐帮会介绍人过来当差.",
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
        message_vision(	"$N朝$n微微笑了笑。\n",this_object(),ob );
        switch( random(2) ) {
                case 0:
                        command( "say 这位" + RANK_D->query_respect(ob)
                                + "，想要刊行您的著作吗？这可找对人了。\n");
                        break;
                case 1:
                        command( "say 这位" + RANK_D->query_respect(ob)
                                + "，我这有各种江湖文士写的笔录，看看您想要买哪一本。\n");
                        break;
        }
}


int do_publish(string arg)
{
	object me, this_book, save_book;
    mapping book_content;

    if(!arg) return notify_fail("您要刊行什么？\n");

	me = this_player();
    this_book = present(arg, me);

    if(!this_book)
            return notify_fail("你身上好像并没有这样东西？\n");
    if(!this_book->query("publishable"))
            return notify_fail("对不起！这样东西我无法刊印。\n");
    if(me->is_busy())
            return notify_fail("你现在正忙着呢。\n");



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
    message_vision(	"$N高高兴兴地把$n写的稿纸拿去刊印了。\n\n",this_object(),me );

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

    if(!arg) return notify_fail("您要收回什么？\n");

	me = this_player();

    if(me->is_busy())
            return notify_fail("你现在正忙着呢。\n");

        k = 0;
		book_found = 0;

		if( sscanf(arg, "book%d", book_no) == 1 ) 
		{
            inv = all_inventory(this_object());
			if(!sizeof(inv))
			    return notify_fail("你想收回的东西我这里没有。\n");
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
				return notify_fail("你想收回的东西我这里没有。\n");
		}
		else 
		{
			return notify_fail("你想收回的东西我这里没有。\n");
        }

		
        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

		if( (ob->query("new_book"))["arthur_id"] != me->query("id") && !wizardp(me) )
			return notify_fail("你又不是主人。\n");

	    message_vision(	"$N听从$n命令把" +(ob->query("new_book"))["arthur"] + "写的"+(ob->query("new_book"))["title"]+"从书架上取掉了。\n\n",
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
                return notify_fail("目前没有可以买的东西。\n");
        // list the cloneable goods
        if (arrayp(goods = query("vendor_goods"))){
                for (i = 0; i < sizeof(goods); i++)
                        printf("%65-s：%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        }
		// list the inventory for sell
        for (i = 0; i < sizeof(inv); i++) 
		{
                if (inv[i]->query("can_sell_book"))
				{
					k++;
					long_name = sprintf("%s(%s%d)",(inv[i]->query("new_book"))["title"],inv[i]->query("id"),k);
                    printf("%35-s 【作者】%20-s ：%s\n", long_name, 
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
                return notify_fail("你想买什么？\n");
        if (ob && ob->query("money_id"))
                return notify_fail("你想买「钱」？？\n");

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
			    return notify_fail("你想买的东西我这里没有。\n");
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
				return notify_fail("你想买的东西我这里没有。\n");
		}
		else 
		{
			return notify_fail("你想买的东西我这里没有。\n");
        }

		
        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");
				

        
  switch (MONEY_D->player_pay(this_player(), ob->query("value") )) {
        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
                set_temp("busy", 1);
                message_vision("$N从$n那里买下了一" + ob->query("unit") + 
                ob->query("name") + "。\n", this_player(), this_object());
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
        return notify_fail("你还未刊行出一本书，就想要钱？\n");
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
 if( (string)me->query_temp("bangs/fam") != "长乐帮" )
                return RANK_D->query_respect(me)+"并非长乐帮中人，不敢劳您大驾。";
 
 if( !(ling = present("bang ling", me)) )
                return RANK_D->query_respect(me)+"连帮印都没有，让在下如何相信于你。";
 
 if (ling->query("job/type")!="伙计")
                return RANK_D->query_respect(me)+"恐怕并没有被指派来此处当差吧。";

 if (me->query_skill("literate",1)<10)
 {              ling->delete("job/name");
                return RANK_D->query_respect(me)+"的文化水平太低恐怕无法胜任我这里的差事，还是回去吧。";
 }
 command("ok");
 obj=new(BOOKTOOL);
 obj->set("owner",me->query("id"));
 
 message_vision( "$N对$n说道：我这里正好缺个抄书的伙计，你随我的书僮去书房吧。\n",this_object(),me );
 message_vision( "$N随后拿出一副"+HIW"文房四宝"NOR+"交给$n，并唤来一位书僮带$n来到书房。\n",this_object(),me );
 obj->move(me);
 me->move(SHUFANG);
 return "好好干吧！";
}
