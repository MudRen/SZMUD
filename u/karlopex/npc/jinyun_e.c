int do_look(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
		{
		if (getuid(me)!= "karlopex"){
			switch( random(4) ) {
				case 0:
					command("cry3");
		                        break;
		                case 1:
					command("bully "+getuid(me));
		                        break;
		                case 2:
		                        command("hate3 " + getuid(me));
		                        break;
		                case 3:
		                        command("nogood " + getuid(me));
		                        break;
		        }
		}else{
			command("say 连你也欺侮我！");
	           	command("cry2");
	           	}
		}
}

int do_fear(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
        {
		if (getuid(me)!= "karlopex")
		{
			if ((string)me->query("gender") == "女性") {
				command("fear " + getuid(me));
				command("say "+RANK_D->query_respect(me)+"居然个同恋，我可不是。\n");
				me->move("/u/karlopex/hmsz_dy");
			}else {
				switch( random(2) ) {
					case 0:
						command("kiss10 situ");
			                        break;
			                case 1:
						command("rascal "+getuid(me));
			                        break;
			        }
	           	}
		}
	}
}
int do_papa(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl")
		switch( random(2) ) {
			case 0:
				command("face2");
	                        break;
	                case 1:
				command("taoyan");
	                        break;
	        }
}
int do_pat(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
		command("pat situ");
}
int do_laugh(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
	if (getuid(me) == "karlopex")
	{
		command("angry");
		message_vision("$N说道：你也取笑我，不理你了！\n", this_object());
		}else	
		command("nolaugh");
}
int do_wa(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
	if (getuid(me) == "karlopex") command("blush karlopex");
	else command("noshame "+getuid(me));
}
int do_jump(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
	if (getuid(me) == "karlopex"){		
                command("shake2");
		return 1;
        }else{
		if ((string)me->query("gender") == "女性") {
	                message_vision("$N张开双臂去抱$n，结果$N力气太小，两个人重重地摔在了地上。\n", this_object(), this_player());
	                command("xixi");
	                command("say 我抱不动你！");
	 		return 1;
	        }else{
	                message_vision("$N向旁一闪身，$n跳了个空，重重地摔在了地上。\n", this_object(), this_player());	        	
	 		return 1;
		}
	}
	
}
int do_miss(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
	if (getuid(me) == "karlopex" || (string)me->query("gender") == "女性"){
		switch( random(3) ) {
			case 0:
				command("shake");
				command("face");
	                        break;
	                case 1:
				command("miss2 "+getuid(me));
	                        break;
	                case 2:
				command("nod2 "+getuid(me));
	                        break;
			}
	}else command("shake "+getuid(me));
}
int do_miss2(string target)
{
        object me;

        me = this_player();
        if (target=="situ" || target=="situ jinyun" || target=="jinyun" || target=="jin" || target=="girl" )
	if (getuid(me) == "karlopex" || (me->query_temp("miss_situ") == 1 && (string)me->query("gender") == "女性")){
		switch( random(3) ) {
			case 0:
				command("say "+me->query("name")+"对我真好！\n");
	                        break;
	                case 1:
				command("jump "+getuid(me));
	                        break;
	                case 2:
				command("lean "+getuid(me));
	                        break;
			}
		me->delete_temp("miss_situ");
	}else command("en "+getuid(me));
}
