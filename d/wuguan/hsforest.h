//Cracked by Kafei
void init()
{
	object maskman, me=this_player();

	if ( interactive(me) && living(me)) {	
		   if (random(10) == 3) {
			message_vision("ͻȻͷ����һ�󾢷磬һ�����������������������\n", me);
			maskman = new(__DIR__"npc/maskman");
			maskman->move(environment(me));
		   }
	}
}
