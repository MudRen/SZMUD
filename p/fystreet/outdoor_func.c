// outdoor_func.c zip@hero 2000.1.27 房子门口功能
void close_door();
void init()
{  add_action("do_open","open");
   add_action("do_close","close");
  add_action("do_knock","knock");
}

int do_open(string arg)
{ 
   int i;
   object me,key,*inv;
   me=this_player();
   if(arg!="door") 
   return notify_fail("你要打开什么？\n");
   if(query("exits/enter")) 
   return notify_fail("门不正大开着吗？\n");
//modified by lion@hero here,解决身上有不同的钥匙不能开门的问题。
   inv = all_inventory(me);
   i=sizeof(inv);
   while(i--)
   {
   	if(((inv[i]->query("id"))=="door key")
   	 &&((inv[i]->query("owner"))==(this_object()->query("owner"))))
   	{
   message_vision("$N掏出一把钥匙打开房门。\n",me);
   set("exits/enter",__DIR__"room/"+(string)this_object()->query("owner")+"_room");
   call_out("close_door",30);
   return 1;
  			}
   	}
message_vision("$N想开门进去，但是，没有这个房间的钥匙。\n",me);
return 1;
}

//added by lion@hero 敲门功能。
int do_knock(string arg)
{
  int i,flag=0;
object *inv;
object room,me;
if(arg!="door")
return notify_fail("你要敲什么？\n");
me=this_player();
if(me->query("id")==this_object()->query("owner"))
  {
    tell_object(me,"这是你自己的房间呀，还敲什么敲？\n");
return notify_fail("是不是忘带钥匙了？可以去房管处要的(ask master about key)。\n");
  }
room=find_object(__DIR__"room/"+this_object()->query("owner")+"_room");
if(!room)
room=load_object(__DIR__"room/"+this_object()->query("owner")+"_room");
if(!room)
return notify_fail("这里没有门，你乱敲什么？\n");
inv=all_inventory(room);
i = sizeof(inv);
while(i--)
{
if(userp(inv[i]))
{
flag=1;
break;
  }
}
message_vision("$N轻轻地敲了敲门。\n",me);
if(!flag)
return notify_fail("现在这个房间里没有任何人，你敲门也没用。\n");
tell_room(room,"外边有人敲门呢，要不要开门呢？\n",this_object());
tell_room(room,"用look out命令看谁在外边，用open door命令开门。\n",this_object());
tell_object(me,"稍等一会儿，看房间里边是不是有人愿意给你开门了。\n");
return 1;
}

int do_close(string arg)
{  object me=this_player();
   if(arg!="door") return notify_fail("你要关上什么？\n");
   if(!query("exits/enter")) return notify_fail("咦，门开着吗？\n");
   delete("exits/enter");
   message_vision("$N将打开着的房门关上。\n",me);
return 1;
}
void close_door()
{ if(!query("exits/enter")) return;
  message_vision("管家婆嘟囔到：又不关门。。。\n管家婆将打开着的房门关上。\n",this_object());
  delete("exits/enter");
return;
} 
