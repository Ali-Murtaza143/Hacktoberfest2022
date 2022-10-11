import React, { useState, useEffect } from "react";
import "./style.css";
import TodoList from "./TodoList";

const getLocalItems = () => {
	let list = localStorage.getItem("lists");
	if (list) {
		return JSON.parse(localStorage.getItem("lists"));
	} else {
		return [];
	}
};

const App = () => {
	const [items, setitems] = useState("");
	const [elements, setElements] = useState(getLocalItems());

	const onchangesDone = (event) => {
		setitems(event.target.value);
	};

	const listOfItems = () => {
		const allinputdata = {
			id: new Date().getTime(),
			name: items,
		};
		setElements([...elements, allinputdata]);
		setitems("");
	};

	const deleteitems = (index) => {
		setElements((oldItems) => {
			return oldItems.filter((value) => {
				localStorage.removeItem(oldItems);
				return index !== value.id;
			});
		});
	};

	useEffect(() => {
		localStorage.setItem("lists", JSON.stringify(elements));
	}, [elements]);

	return (
		<div className="todo_div">
			<h1> Todo</h1>
			<input
				type="text"
				name="username"
				id="txt_username"
				placeholder="Enter Your Todo"
				className="txt_username"
				value={items}
				onChange={onchangesDone}
			/>
			<br />
			<input
				type="button"
				name="add todo"
				id="add_todo"
				value="add"
				className="button"
				onClick={listOfItems}
			/>

			<div className="elements">
				<ol>
					{elements.map((element) => {
						return (
							<TodoList
								key={element.id}
								id={element.id}
								text={element.name}
								onSelect={deleteitems}
							/>
						);
					})}
				</ol>
			</div>
		</div>
	);
};

export default App;
