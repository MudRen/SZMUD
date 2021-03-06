//                标准描述长度示例                                   |
// 奈何的工作室，第三版。简单而实在，不再炫耀创意  /u/naihe/naihe_room.c
// by naihe  2002-07-04

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",BLU"峰顶小屋"NOR);
	set("long",@LONG
这间屋子空荡荡的，门对面墙上的一只灯泡里灯光不再摇曳，而原先的那种
不知从何方吹来的风也平静下来了。灯下摆放的一板木床依然整齐地叠放着一些
书籍、衣服、被子和枕头，枕头边上竖着的嵌在小木框里的照片，也似乎不是以
前那幅了。屋子里不变的是它的沉寂，留在这里仍是会让人思索着，感觉平静而
却又有千丝万缕的念头纷涌而来。
LONG
	);
	set("valid_startroom", 1);
	set("no_clean_up","1");  // 这句话是没有任何意义的，要不更新房间，唯有用别的方法。
	set("item_desc",([
            "photo":"这是一幅目光深邃的猪头的特写照片，你却看不出来它在思考着什么。\n",
	    "zhaopian":"这是一幅目光深邃的猪头的特写照片，你却看不出来它在思考着什么。\n",
	    "bed":"一张小木床，似乎很久没人睡过了，却似乎仍散发着某种幽幽的香气。\n",
	    "muchuang":"一张小木床，似乎很久没人睡过了，却似乎仍散发着某种幽幽的香气。\n",
	    "bulb":"原来这是一个装着数颗宝石的灯泡，难怪会如此持久散发着光芒。\n",
	    "dengpao":"原来这是一个装着数颗宝石的灯泡，难怪会如此持久散发着光芒。\n",
	    "quilt":"一张棉被，叠放得整整齐齐地。\n",
	    "beizi":"一张棉被，叠放得整整齐齐地。\n",
	    "book":"一些书籍，最上面那本封面似乎是个裸体女子，天哪。。。\n",
	    "shuji":"一些书籍，最上面那本封面似乎是个裸体女子，天哪。。。\n",
	    "yifu":"几件衣服，没什么特别之处。\n",
	    "cloth":"几件衣服，没什么特别之处。\n",
	    "pillow":"一个小棉枕，上边竟留着一丝长长秀发。\n",
	    "zhentou":"一个小棉枕，上边竟留着一丝长长秀发。\n",
	]));
	set("exits",([
	    "out":"/d/huashan/fengding",
//	    "dc":"/clone/misc/naihe/dc_dating",
//	    "west":"/u/spark/spark_room",
	]));

	setup();
	call_other("/clone/board/naihe_b","???");

}

void init()
{
	add_action("do_sleep","sleep");
	add_action("do_meeting","meeting");
	if(this_player()->query("id")=="naihe" || wizardp(this_player()))
	{
		add_action("do_note","note");
		add_action("do_armor","armor");
		add_action("do_gem","gem");
	}

	if(this_player()->query("id")!="naihe")
	{
		add_action("do_nomore","more");
		add_action("do_nomore","cat");
	}
}

int do_sleep()
{
	object me=this_player();
	int jing,jingli,neili,qi;

	if(me->query("id")=="naihe" && me->query("name")=="奈何")
		message_vision(""MAG"$N阔步走向床边，躺下歇息了片刻。"NOR"\n",me);

	if(me->query("id")=="spark" && me->query("name")=="闪烁")
		message_vision(""MAG"$N轻步走向床边，躺下歇息了片刻。"NOR"\n",me);

	if(me->query("id")!="naihe" && me->query("id")!="spark")
	{
		write("难道你想躺别人的床上去睡？太不礼貌了吧。\n");
		message("vision",""CYN""+me->query("name")+"在床边走来走去，似乎想躺下睡一觉。\n"NOR,environment(me),me);
		return 1;
	}

	jing=me->query("max_jing");
	jingli=me->query("max_jingli");
	neili=me->query("max_neili");
	qi=me->query("max_qi");

	message_vision(""MAG"$N小憩醒来，觉得精神奕奕。"NOR"\n",me);

	me->set("jingli",jingli);
	me->set("jing",jing);
	me->set("neili",neili);
	me->set("qi",qi);

	return 1;
}



int do_gem()
{
	object me,ob;
	ob=new(__DIR__"obj/gem");
	me=this_player();

	message_vision(""CYN"$N在被子堆里掏了掏，掏出了一"+ob->query("unit")+ob->query("name")+"。"NOR"\n",me);
	ob->move(me);
	return 1;
}

int do_nomore()
{
	write(""BLU"你忽地听到一个声音幽幽地说道：“唉，怎么又有人在呢……”"NOR"\n");
	write("你一下子呆住了，竟然忘记了自己想要做什么。\n");
	return 1;
}

int do_note()
{
	object me=this_player();

	if(me->query("id")=="naihe" || me->query("id")=="spark" || wizardp(me))
	{
		new(__DIR__"obj/note_naihe")->move(me);
		message_vision(""BLU"$N在墙边拍了拍，忽地凭空掉下了一个小本子，$N连忙接住，觉得怪异莫名。"NOR"\n",this_player());
		return 1;
	}

	return 0;
}

int do_armor()
{
	object me,oba,obb,obc,obd,obe,obf;
	me=this_player();
	oba=new(__DIR__"obj/anyue-jian");
	obb=new(__DIR__"obj/ay-cloth");
	obc=new(__DIR__"obj/ay-pifeng");
	obd=new(__DIR__"obj/ay-kui");
	obe=new(__DIR__"obj/ay-ring");
	obf=present("cloth",me);

	if(me->query("id")=="naihe" || me->query("id")=="spark" || wizardp(me))
	{
		message_vision(""CYN"$N在墙上拍了拍，只见其中几块砖头缩了进去，露出了一个小洞。\n$N从小洞里拿出了一整套装备，又拍了拍墙上，砖头重回原处把小洞封了起来。"NOR"\n",me);

		if(!present("anyue jian",me)) oba->move(me);
		if(!present("anyue cloth",me)) obb->move(me);
		if(!present("anyue manteau",me)) obc->move(me);
		if(!present("anyue kui",me)) obd->move(me);
		if(!present("anyue ring",me)) obe->move(me);
		if(present("cloth",me)) destruct(obf);

		write("all armor ok.\n");
		return 1;
	}
	message_vision(""CYN"$N在墙边上左拍拍，右拍拍，楞是找不出小洞在哪里。"NOR"\n",me);
	return 1;
}

int do_meeting()
{
	object me=this_player();
	string name=me->query("name");

	message("vision",name+"往私人聊天室里走了进去。\n"NOR,environment(me),me);
	tell_object(me,"你往私人聊天室里走了进去。\n");
	me->move(__DIR__"naihe_meetingroom");
	message("vision",name+"走了过来。\n"NOR,environment(me),me);
	return 1;
}
