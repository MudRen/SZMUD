//master_func.c      zip@hero  2000.1.27 房管功能
#include <ansi.h>
#define __ROOMDIR__ "/p/fystreet/"
void init()
{  add_action("do_ask","ask");}

int do_ask(string arg)
{ object ob,me,key,gold,builder;
  string dest,topic,topicowner,owner,roomid,rest,dir,dir1;
  int i;
  me=this_object();ob=this_player();
  if(!arg||sscanf(arg,"%s about %s",dest,topic)!=2) return 0;
  if(dest!="room master"&&dest!="master") return 0;
  message_vision("$N向$n询问有关『"+topic+"』的事。\n",ob,me);
  if(topic=="建房")
    {message_vision(CYN"\n$N说道：不错，只要你有足够的钱庄存款，就可以在神州大街建一座自己的房子。\n"NOR,me);
     message_vision(CYN"$N说道：详情可以看那边的(note)。\n"NOR,me);return 1;}
  if(topic=="key")
    {if(!(ob->query("roomid"))) {message_vision("$N说道：咦，你在这儿有房子吗？\n",me);return 1;}
     key=new(__DIR__"obj/key");key->set("owner",ob->query("id"));
     key->set("long","一把精致的钥匙。一面写着：神州大街，另一面写着："+ob->query("name")+"。\n");
     message_vision("$N递给$n一把钥匙：这是你的房门钥匙，拿好了。\n",me,ob);
     key->move(ob);return 1;}
  if(topic=="我要建房")
    {if(ob->query_temp("inbuild")) {message_vision("$N对$n说道：你还没选好地方吗？\n",me,ob);return 1;}
     if(ob->query("roomid")>0) 
       {message_vision(CYN"$N对$n说道：你不是有房子吗？还是问我要房子钥匙吧。\n"NOR,me,ob);return 1;}
     message_vision(CYN"$N对$n说道：要在神州大街住下啊，不简单哪。\n"NOR,me,ob);
     message_vision(CYN"$N说道：建房要 888 Gold 的钱庄存款。\n\n"NOR,me);
//     gold=present("gold_money",ob);
//     if(!gold) {message_vision("$N对$n说道：你身上没有gold耶。\n",me,ob);return 1;}
     if(ob->query("balance")<8880000)
      {message_vision("$N翻起手头的一本帐册，过了会儿对$n说道：你的钱庄存款好像不够耶。\n",me,ob);
       return 1;}
     ob->add("balance",-8880000);
     builder=new(__DIR__"builder");builder->set("owner",ob->query("id"));
     builder->move(environment(ob));builder->set_leader(ob);
     message_vision("$N点了点头，向屋内喊到：$n！\n",me,builder);
     message_vision("$N从屋里走出来。\n",builder);ob->set_temp("inbuild",1);
     message_vision(CYN"$N对$n说道：你们先去选地方吧。\n\n"NOR,me,ob);
     return 1;
    }
   rest=read_file(__DIR__"room.list");
   if(topic=="现有住户")
    {message_vision(CYN"$N说道：目前已经在神州大街住下的有赫赫有名的：\n"NOR,me);   
     while(rest!="")
      {sscanf(rest,":%s,%s:%s",owner,roomid,rest);
      message_vision("  "+owner,me);}
     message_vision(CYN"\n$N说道：你可以询问他们的房子在哪儿。\n\n"NOR,me);
     return 1;
    }
   if(sscanf(topic,"%s的房子",topicowner)==1)
    {if(topicowner=="我") topicowner=ob->query("name");
      while(rest!="")
      {sscanf(rest,":%s,%s:%s",owner,roomid,rest);
       if(topicowner==owner)
        {sscanf(roomid,"%d",i);
	dir1="东";if(i%2) dir1="西";
        message_vision(CYN"$N说道："+owner+"的房子是神州大街"+
             chinese_number((i)/100)+"号"+dir1+"。"NOR,me);
        message_vision(CYN"从天骄门进去往北"+chinese_number((i)/100)+"步"+dir1+"边那座就是。\n\n"NOR,me);
        return 1;
      } }
     message_vision(CYN"$N说道："+topicowner+"目前在神州大街还没有自己的房子。\n\n"NOR,me);
     return 1;
    }
message_vision(CYN"$N说道：你可以问我：建房，我要建房，key。\n\n"NOR,me);
return 1;
}