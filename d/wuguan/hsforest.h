//Cracked by Kafei
void init()
{
	object maskman, me=this_player();

	if ( interactive(me) && living(me)) {	
		   if (random(10) == 3) {
			message_vision("突然头顶上一阵劲风，一个蒙面大汉由树上跳了下来！\n", me);
			maskman = new(__DIR__"npc/maskman");
			maskman->move(environment(me));
		   }
	}
}
