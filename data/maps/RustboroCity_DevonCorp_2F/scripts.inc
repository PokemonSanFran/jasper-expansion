DrivesLab_1F_FrustratedScientist::
	lock
	msgbox DrivesLab_1F_FrustratedScientist_Text_0
	closemessage
	faceplayer
	msgbox DrivesLab_1F_FrustratedScientist_Text_1
	closemessage
	release
	return


DrivesLab_1F_WorriedEconomic::
	msgbox DrivesLab_1F_WorriedEconomic_Text_0, MSGBOX_NPC
	return


DrivesLab_1F_Singer::
	msgbox DrivesLab_1F_Singer_Text_0, MSGBOX_NPC
	return


DrivesLab_1F_ContinuousWork::
	msgbox DrivesLab_1F_ContinuousWork_Text_0, MSGBOX_NPC
	return


DrivesLab_1F_TiredScientist::
	msgbox DrivesLab_1F_TiredScientist_Text_0, MSGBOX_NPC
	return


 
.set LOCALID_FOSSIL_SCIENTIST, 5

RustboroCity_DevonCorp_2F_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
@	compare VAR_FOSSIL_RESURRECTION_STATE, 1
@	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
@	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
@	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
@	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
@	lock
@	faceplayer
@	compare VAR_FOSSIL_RESURRECTION_STATE, 1
@	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
@	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
@	lock
@	faceplayer
@	compare VAR_FOSSIL_RESURRECTION_STATE, 1
@	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
@	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
@	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
@	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
@	lock
@	faceplayer
@	compare VAR_FOSSIL_RESURRECTION_STATE, 1
@	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
@	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
@	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
@	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
@	lock
@	faceplayer
@	compare VAR_FOSSIL_RESURRECTION_STATE, 1
@	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
@	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
@	lock
@	faceplayer
@	compare VAR_FOSSIL_RESURRECTION_STATE, 2
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
@	compare VAR_FOSSIL_RESURRECTION_STATE, 1
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
@	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
@	checkitem ITEM_ROOT_FOSSIL, 1
@	compare VAR_RESULT, TRUE
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
@	checkitem ITEM_CLAW_FOSSIL, 1
@	compare VAR_RESULT, TRUE
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
@	release
@	end

@ This whole section has needless duplication and could be condensed considerably
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
@	closemessage
@	playse SE_PIN
@	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
@	waitmovement 0
@	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
@	waitmovement 0
@	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
@	checkitem ITEM_CLAW_FOSSIL, 1
@	compare VAR_RESULT, TRUE
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
@	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
@	end

RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
@	bufferitemname 0, ITEM_ROOT_FOSSIL
@	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
@	removeitem ITEM_ROOT_FOSSIL
@	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
@	setvar VAR_WHICH_FOSSIL_REVIVED, 1
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
@	closemessage
@	playse SE_PIN
@	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
@	waitmovement 0
@	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
@	waitmovement 0
@	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
@	checkitem ITEM_ROOT_FOSSIL, 1
@	compare VAR_RESULT, TRUE
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
@	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
@	end

RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
@	bufferitemname 0, ITEM_CLAW_FOSSIL
@	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
@	removeitem ITEM_CLAW_FOSSIL
@	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
@	setvar VAR_WHICH_FOSSIL_REVIVED, 2
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
@	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
@	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
@	compare VAR_WHICH_FOSSIL_REVIVED, 1
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_LileepReady
@	compare VAR_WHICH_FOSSIL_REVIVED, 2
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_AnorithReady
@	end

RustboroCity_DevonCorp_2F_EventScript_LileepReady::
@	bufferspeciesname 1, SPECIES_LILEEP
@	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
@	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
@	end

RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
@	bufferspeciesname 1, SPECIES_ANORITH
@	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
@	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
@	setvar VAR_TEMP_1, SPECIES_LILEEP
@	givemon SPECIES_LILEEP, 20, ITEM_NONE
@	compare VAR_RESULT, 0
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
@	compare VAR_RESULT, 1
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
@	goto Common_EventScript_NoMoreRoomForPokemon
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
@	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
@	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
@	call Common_EventScript_GetGiftMonPartySlot
@	call Common_EventScript_NameReceivedPartyMon
@	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
@	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
@	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
@	call Common_EventScript_NameReceivedBoxMon
@	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
@	end

RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
@	call Common_EventScript_TransferredToPC
@	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
@	bufferspeciesname 1, SPECIES_LILEEP
@	playfanfare MUS_OBTAIN_ITEM
@	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
@	waitmessage
@	waitfanfare
@	bufferspeciesname 0, SPECIES_LILEEP
@	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
@	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
@	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
@	setvar VAR_TEMP_1, SPECIES_ANORITH
@	givemon SPECIES_ANORITH, 20, ITEM_NONE
@	compare VAR_RESULT, 0
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
@	compare VAR_RESULT, 1
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
@	goto Common_EventScript_NoMoreRoomForPokemon
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
@	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
@	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
@	call Common_EventScript_GetGiftMonPartySlot
@	call Common_EventScript_NameReceivedPartyMon
@	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
@	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
@	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
@	compare VAR_RESULT, NO
@	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
@	call Common_EventScript_NameReceivedBoxMon
@	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
@	end

RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
@	call Common_EventScript_TransferredToPC
@	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
@	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
@	bufferspeciesname 1, SPECIES_ANORITH
@	playfanfare MUS_OBTAIN_ITEM
@	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
@	waitmessage
@	waitfanfare
@	bufferspeciesname 0, SPECIES_ANORITH
@	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
@	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
@	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
@	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
@	waitmessage
@	multichoice 17, 6, MULTI_FOSSIL, FALSE
@	switch VAR_RESULT
@	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
@	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
@	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
@	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
@	end

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
@	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
@	end

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
@	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
@	end

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
@	lock
@	faceplayer
@	compare VAR_FOSSIL_RESURRECTION_STATE, 1
@	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
@	compare VAR_RUSTBORO_CITY_STATE, 6
@	goto_if_ge RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
@	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
@	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
@	release
@	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
@	.string "We're developing a device for talking\n"
@	.string "with POKéMON.\p"
@	.string "But we haven't had much success…$"

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
@	.string "I'm developing new kinds of\n"
@	.string "POKé BALLS…\p"
@	.string "But I haven't made much headway…$"

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
@	.string "We finally made new kinds of\n"
@	.string "POKé BALLS!\p"
@	.string "The REPEAT BALL makes it easier to\n"
@	.string "catch POKéMON you've caught before.\p"
@	.string "The TIMER BALL gets better at catching\n"
@	.string "POKéMON the longer a battle runs.\p"
@	.string "Both are proudly developed by\n"
@	.string "the DEVON CORPORATION.\p"
@	.string "Please give them a try!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
@	.string "I made the POKéNAV!\p"
@	.string "As an engineer, I feel blessed to have\n"
@	.string "made something so great!$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
@	.string "Oh, wow!\n"
@	.string "That's a POKéNAV!\p"
@	.string "It came about as a result of our\n"
@	.string "PRESIDENT's desire to learn about\l"
@	.string "the feelings of POKéMON.\p"
@	.string "Would you like me to describe its\n"
@	.string "features in detail?\p"
@	.string "No, no. I think you'll find out just by\n"
@	.string "trying the POKéNAV out.$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
@	.string "I'm trying to develop a device that\n"
@	.string "visually reproduces the dreams of\l"
@	.string "POKéMON…\p"
@	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
@	.string "I've been trying to develop a device\n"
@	.string "that resurrects POKéMON from fossils…\p"
@	.string "And, it's working!$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
@	.string "Wait! That thing you have there…\n"
@	.string "Is that a POKéMON fossil?\p"
@	.string "Would you like to bring that POKéMON\n"
@	.string "back to life?\p"
@	.string "I can with my newly developed\n"
@	.string "FOSSIL REGENERATOR.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
@	.string "Oh, is that so?\p"
@	.string "DEVON's technological expertise\n"
@	.string "is outstanding, I tell you.$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
@	.string "Oh, now that's a surprise!\n"
@	.string "You have not one, but two, fossils?\p"
@	.string "Unfortunately, my machine can only\n"
@	.string "regenerate one POKéMON at a time.\p"
@	.string "Would you like to pick one of your\n"
@	.string "fossils for regeneration?$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
@	.string "Excellent!\n"
@	.string "Let's do this right away.\p"
@	.string "{PLAYER} handed the {STR_VAR_1} to\n"
@	.string "the DEVON RESEARCHER.$"

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
@	.string "The FOSSIL REGENERATOR, which I made,\n"
@	.string "is incredible.\p"
@	.string "But it has one drawback--it takes\n"
@	.string "a long time to work.\p"
@	.string "So, uh… How about you go for a stroll\n"
@	.string "and look around for a while?$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
@	.string "Thanks for waiting!\p"
@	.string "Your fossilized POKéMON has been\n"
@	.string "brought back to life!\p"
@	.string "The fossil was an ancient POKéMON.\n"
@	.string "{STR_VAR_2}, it was!$"

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
@	.string "{PLAYER} received {STR_VAR_2} from\n"
@	.string "the DEVON RESEARCHER.$"

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
@	.string "Uh-oh, you've got too many POKéMON.\n"
@	.string "You have no room for this one.$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
@	.string "I'm trying to develop a new feature\n"
@	.string "for the POKéNAV…\p"
@	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
@	.string "Well, now what shall I work on\n"
@	.string "developing next?\p"
@	.string "Our company allows us to make our\n"
@	.string "inspirations into reality.\p"
@	.string "One couldn't ask for a better\n"
@	.string "environment as an engineer.$"

DrivesLab_1F_FrustratedScientist_Text_0:
	.string "Hmmm, no… Not quite… Aaagh, I'm so\n"
	.string "close, but I can't figure this thing\l"
	.string "out!$"

DrivesLab_1F_FrustratedScientist_Text_1:
	.string "Oh! Ah, sorry… Got a little caught up in\n"
	.string "my work.$"

DrivesLab_1F_WorriedEconomic_Text_0:
	.string "We're trying to compete with Unova's\n"
	.string "C-Gear.\p"
	.string "They're a raging success, so we can't\n"
	.string "rest on our laurels from a single bout\l"
	.string "of strong sales.\p"
	.string "We'll have to keep at it to make sure\n"
	.string "the P-Drive becomes the number-one\l"
	.string "Trainer's gadget!$"

DrivesLab_1F_Singer_Text_0:
	.string "P-Driiiiive… P-Driiiiive… Livin' a better\n"
	.string "life with my P-Driiiiive!\p"
	.string "Well, how was that? How was my\n"
	.string "commercial song?\l"
	.string "Oh…$"

DrivesLab_1F_ContinuousWork_Text_0:
	.string "We're continuously working on making\n"
	.string "the P-Drive the ultimate gadget for\l"
	.string "Trainers all across the region.\p"
	.string "We've got our sights set on the world,\n"
	.string "though the competition's pretty\l"
	.string "stiff…\p"
	.string "Doesn't mean we'll give up on trying,\n"
	.string "though!$"

DrivesLab_1F_TiredScientist_Text_0:
	.string "Johto has the PokéGear, Hoenn's got\n"
	.string "their PokéNav, Sinnoh's got the\l"
	.string "Pokétch… and then there's Unova with\l"
	.string "the C-Gear.\p"
	.string "It's my job to make sure we know what\n"
	.string "they're doing, so we're always one step\l"
	.string "ahead of them.\p"
	.string "I do need a break, though… You wouldn't\n"
	.string "believe how tiring this can be.$"
